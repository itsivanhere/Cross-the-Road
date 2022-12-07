#include "Koin.h"

void Koin::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 16;
	intRect.width = 16;
	maxSize = 64;
	plusWidth = 16;
}

void Koin::initSprite()
{
	sprite.setTextureRect(intRect);
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		sprite.setPosition(42.f, 0.f-16.f);
		break;
	case 1:
		sprite.setPosition(142.f, 0.f - 16.f);
		break;
	case 2:
		sprite.setPosition(242.f, 0.f - 16.f);
		break;
	default:
		break;
	}
}


Koin::Koin()
{
	this->initVariables();
	this->initSprite();
	this->initDirection();
}

Koin::~Koin()
{
}

Koin::Koin(const Koin& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

void Koin::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
	updateAnimation();
}

void Koin::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
