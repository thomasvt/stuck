#include <Gamebuino-Meta.h>
#include <rectangle.h>

void Rectangle::log() const
{
	SerialUSB.printf("(%i, %i, %i, %i)\n", left, top, right, bottom);
}

