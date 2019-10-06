using System;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using PogoDataConverter.LevelGenerator;
using Color = System.Drawing.Color;
using Path = System.IO.Path;

namespace PogoDataConverter
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string _lastFile;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void ProcessFile(string filename)
        {
            if (!File.Exists(filename) || Path.GetExtension(filename) != ".png")
            {
                MessageBox.Show("png files only.");
                return;
            }

            var bitmap = new Bitmap(filename);
            CodeTextBox.Text = GenerateSpriteCode(bitmap);
            _lastFile = filename;
        }

        private string GenerateSpriteCode(Bitmap bitmap)
        {
            var pixels = ConvertTo565(bitmap);
            var rectangle = new Rectangle(0, 0, bitmap.Width, bitmap.Height);
            if (NoCropCheckBox.IsChecked == false)
            {
                rectangle = GetClippableRectangle(pixels);
                pixels = Clip(pixels, rectangle);
            }
            if (OneBitCheckBox.IsChecked.Value)
                return GenerateBitmap1Code(pixels, rectangle, bitmap.Width, bitmap.Height);
            else
                return GenerateBitmapCode(pixels, rectangle, bitmap.Width, bitmap.Height);
        }

        private string GenerateBitmap1Code(ushort[,] clippedPixels, Rectangle clipRectangle, int width, int height)
        {
            var sb = new StringBuilder();
            sb.AppendLine("const uint8_t data[] PROGMEM = {");
            for (var y = 0; y < clipRectangle.Height; y++)
            {
                var value = 0;
                for (var x = 0; x < clipRectangle.Width; x++)
                {
                    var bitNumber = x % 8;
                    if (bitNumber == 0)
                        value = 0;
                    var bit = clippedPixels[x, y] > 0;
                    if (bit)
                    {
                        value |= 1 << (7-bitNumber);
                    }

                    if (bitNumber == 7)
                        sb.Append($"{value}, ");
                }
                sb.AppendLine();
            }

            sb.AppendLine("};");
            sb.AppendLine();
            var anchorInCenter = AnchorInCenterCheckBox.IsChecked.Value ? "true" : "false";
            sb.AppendLine($"Bitmap1 my_bitmap = Bitmap1(data, {width}, {height}, {clipRectangle.X}, {clipRectangle.Y}, {clipRectangle.Width}, {clipRectangle.Height}, {anchorInCenter}); ");

            return sb.ToString();
        }

        private string GenerateBitmapCode(ushort[,] clippedPixels, Rectangle clipRectangle, int originalWidth, int originalHeight)
        {
            var sb = new StringBuilder();
            sb.AppendLine("const uint16_t data[] PROGMEM = {");
            var anchorInCenter = AnchorInCenterCheckBox.IsChecked.Value ? "1" : "0";
            sb.AppendLine($"{originalWidth}, {originalHeight}, {clipRectangle.X}, {clipRectangle.Y}, {clipRectangle.Width}, {clipRectangle.Height}, {anchorInCenter}, ");

            for (var y = 0; y < clipRectangle.Height; y++)
            {
                for (var x = 0; x < clipRectangle.Width; x++)
                {
                    sb.Append($"0x{clippedPixels[x, y]:X}, ");
                }

                sb.AppendLine();
            }
            sb.AppendLine("};");
            
            return sb.ToString();
        }

        public static ushort[,] Clip(ushort[,] original, Rectangle clip)
        {
            var result = new ushort[clip.Width, clip.Height];
            for (var y = 0; y < clip.Height; y++)
            {
                for (var x = 0; x < clip.Width; x++)
                    result[x, y] = original[x + clip.X, y + clip.Y];
            }

            return result;
        }

        private static Rectangle GetClippableRectangle(ushort[,] pixels)
        {
            var top = 0;
            while (RowIsEmpty(pixels, top)) top++;

            var bottom = pixels.GetLength(1) - 1;
            while (RowIsEmpty(pixels, bottom)) bottom--;

            var left = 0;
            while (ColumnIsEmpty(pixels, left)) left++;

            var right = pixels.GetLength(0) - 1;
            while (ColumnIsEmpty(pixels, right)) right--;

            return new Rectangle(left, top, right - left + 1, bottom - top + 1);
        }

        private static ushort[,] ConvertTo565(Bitmap bitmap)
        {
            var pixels = new ushort[bitmap.Width, bitmap.Height];
            for (var y = 0; y < bitmap.Height; y++)
            {
                for (var x = 0; x < bitmap.Width; x++)
                    pixels[x, y] = ConvertTo565(bitmap.GetPixel(x, y));
            }

            return pixels;
        }

        private const int TransparencyTreshold = 20;

        private static ushort ConvertTo565(Color pixel)
        {
            if (pixel.A < TransparencyTreshold)
                return 0; // transparant
            if (pixel == Color.Black)
                return 0x0001; // black is occupied for transparent (much more performant to check for 0 in engine than arbitrary color), so we adjust actual black to almost-black.
            // the 565 format: g2 g1 g0 b4 b3 b2 b1 b0   r4 r3 r2 r1 r0 g5 g4 g3
            var red = CompressChannelValue(pixel.R, 5);
            var green = CompressChannelValue(pixel.G, 6);
            var blue = CompressChannelValue(pixel.B, 5);
            var value = (blue << 8) | (red << 3) | ((0b000111 & green) << 13) | ((0b111000 & green) >> 3);

            return (ushort)value;
        }

        private static bool RowIsEmpty(ushort[,] pixels, int y)
        {
            return Enumerable.Range(0, pixels.GetLength(0)).All(x => pixels[x, y] == 0);
        }

        private static bool ColumnIsEmpty(ushort[,] pixels, int x)
        {
            return Enumerable.Range(0, pixels.GetLength(1)).All(y => pixels[x, y] == 0);
        }

        private static bool ColumnIsEmpty(Bitmap bitmap, int x)
        {
            return Enumerable.Range(0, bitmap.Height).All(y => bitmap.GetPixel(x, y).A < TransparencyTreshold);
        }

        private static ushort CompressChannelValue(byte value, int bitCount)
        {
            return (ushort)(value * (1 << bitCount) / 256);
        }

        private void Window_Drop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                var files = (string[])e.Data.GetData(DataFormats.FileDrop);
                ProcessFile(files[0]);
            }
        }

        private void CodeTextBox_OnPreviewDragOver(object sender, DragEventArgs e)
        {
            e.Handled = true; // bypass framework to allow dropping
        }

        private void AnchorInCenterCheckBox_OnClick(object sender, RoutedEventArgs e)
        {
            if (_lastFile != null)
                ProcessFile(_lastFile); // redo file
        }

        private void FontRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            if (_lastFile != null)
                ProcessFile(_lastFile); // redo file
        }

        private void SpriteRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            if (_lastFile != null)
                ProcessFile(_lastFile); // redo file
        }

        private void TextTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            if (TextTextBox.Text.Length > 0 && File.Exists(FontFileTextBox.Text))
            {
                GenerateTextSprite(TextTextBox.Text, new Bitmap(FontFileTextBox.Text));
            }
        }

        private const int GlyphWidth = 8;

        private void GenerateTextSprite(string text, Bitmap font)
        {
            var sprite = new Bitmap(text.Length * GlyphWidth, font.Height);
            var cursor = 0;
            foreach (var c in text)
            {
                if (c == ' ')
                {
                    cursor += 3;
                    continue;
                }
                var glyphIndex = GetGlyphIndex(c);
                cursor = DrawGlyph(sprite, cursor, glyphIndex, font);
            }

            TextCodeTextBox.Text = GenerateSpriteCode(sprite);
        }

        private static int DrawGlyph(Bitmap sprite, int cursor, int glyphIndex, Bitmap font)
        {
            for (var y = 0; y < font.Height; y++)
                for (var x = 0; x < GlyphWidth; x++)
                    sprite.SetPixel(x+cursor, y, font.GetPixel(glyphIndex * GlyphWidth + x, y));
            cursor += GlyphWidth;
            while (ColumnIsEmpty(sprite, cursor - 1))
                cursor--;
            return cursor;
        }

        const int uppercase_start = 10;
        const int lowercase_start = 36;
        const int others_start = 62;
        const int space = 79;

        private int GetGlyphIndex(char ch)
        {
            if (ch >= 'a' && ch <= 'z')
                return ch - 'a' + lowercase_start;
            if (ch == ' ')
                return space;
            if (ch >= 'A' && ch <= 'Z')
                return ch - 'A' + uppercase_start;
            if (ch >= '0' && ch <= '9')
                return ch - '0';

            switch (ch)
            {
                case '.': return others_start;
                case ',': return others_start + 1;
                case ':': return others_start + 2;
                case '!': return others_start + 3;
                case '?': return others_start + 4;
                case '(': return others_start + 5;
                case ')': return others_start + 6;
                case '\\': return others_start + 7;
                case '/': return others_start + 8;
                case '"': return others_start + 9;
                case '&': return others_start + 10;
                case '$': return others_start + 11;
                case '%': return others_start + 12;
                case '*': return others_start + 13;
                case '+': return others_start + 14;
                case '-': return others_start + 15;
                case '_': return others_start + 16;

                default:
                    return others_start + 4; // show '?' if unknown char
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            OutputTextBox.Visibility = Visibility.Collapsed;
            OutputTextBox.Text = string.Empty;
            var generator = new LevelCodeGenerator();
            generator.OnLog += (o, s) =>
            {
                OutputTextBox.Visibility = Visibility.Visible;
                OutputTextBox.Text += s + Environment.NewLine;
            };
            LevelCodeTextBox.Text = generator.Generate(LevelFolderTextBox.Text);
        }
    }
}
