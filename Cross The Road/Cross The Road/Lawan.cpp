#include "Lawan.h"

void Lawan::initVariables()
{

}

Lawan::Lawan()
{

}

Lawan::~Lawan()
{
}

Lawan::Lawan(const Lawan& n)
{
}

void Lawan::render(RenderTarget& target)
{
	target.draw(this->sprite);
}

Clock& Lawan::get_time()
{
	return this->time;
}


