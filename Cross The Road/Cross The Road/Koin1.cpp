#include "Koin1.h"

void Koin1::initSprite()
{
	texture.loadFromFile("images/Silvercoin.png");
	sprite.setTexture(texture);
	Koin::initSprite();
}

Koin1::Koin1()
{
	initVariables();
	initSprite();
}

Koin1::~Koin1()
{
}

Koin1::Koin1(const Koin1& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

int Koin1::getType()
{
	return 0;
}
