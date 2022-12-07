#include "Gerak.h"

void Gerak::initDirection()
{
	direction.x = 0.f;
	direction.y = 3.f;
}

void Gerak::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}
