﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System.Xml.Serialization;

// 
// This source code was auto-generated by xsd, Version=4.6.1055.0.
// 


/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
public partial class tileset
{

    private tilesetGrid[] gridField;

    private tilesetTile[] tileField;

    private string versionField;

    private string tiledversionField;

    private string nameField;

    private string tilewidthField;

    private string tileheightField;

    private string tilecountField;

    private string columnsField;

    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("grid", Form = System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public tilesetGrid[] grid
    {
        get
        {
            return this.gridField;
        }
        set
        {
            this.gridField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("tile", Form = System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public tilesetTile[] tile
    {
        get
        {
            return this.tileField;
        }
        set
        {
            this.tileField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string version
    {
        get
        {
            return this.versionField;
        }
        set
        {
            this.versionField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string tiledversion
    {
        get
        {
            return this.tiledversionField;
        }
        set
        {
            this.tiledversionField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string name
    {
        get
        {
            return this.nameField;
        }
        set
        {
            this.nameField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string tilewidth
    {
        get
        {
            return this.tilewidthField;
        }
        set
        {
            this.tilewidthField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string tileheight
    {
        get
        {
            return this.tileheightField;
        }
        set
        {
            this.tileheightField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string tilecount
    {
        get
        {
            return this.tilecountField;
        }
        set
        {
            this.tilecountField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string columns
    {
        get
        {
            return this.columnsField;
        }
        set
        {
            this.columnsField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class tilesetGrid
{

    private string orientationField;

    private string widthField;

    private string heightField;

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string orientation
    {
        get
        {
            return this.orientationField;
        }
        set
        {
            this.orientationField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string width
    {
        get
        {
            return this.widthField;
        }
        set
        {
            this.widthField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string height
    {
        get
        {
            return this.heightField;
        }
        set
        {
            this.heightField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class tilesetTile
{

    private tilesetTileImage[] imageField;

    private string idField;

    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("image", Form = System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public tilesetTileImage[] image
    {
        get
        {
            return this.imageField;
        }
        set
        {
            this.imageField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string id
    {
        get
        {
            return this.idField;
        }
        set
        {
            this.idField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class tilesetTileImage
{

    private string widthField;

    private string heightField;

    private string sourceField;

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string width
    {
        get
        {
            return this.widthField;
        }
        set
        {
            this.widthField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string height
    {
        get
        {
            return this.heightField;
        }
        set
        {
            this.heightField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string source
    {
        get
        {
            return this.sourceField;
        }
        set
        {
            this.sourceField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
public partial class TsxFile
{

    private tileset[] itemsField;

    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("tileset")]
    public tileset[] Items
    {
        get
        {
            return this.itemsField;
        }
        set
        {
            this.itemsField = value;
        }
    }
}