#include "Mobil2.h"

void Mobil2::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 678;
	intRect.width = 1542;
	maxSize = 4626;
	plusWidth = 1542;
}

void Mobil2::initSprite()
{
	texture.loadFromFile("images/truk.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(this->intRect);
	sprite.setScale(0.05f, 0.05f);

	int rando = rand() % 2;
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(120.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	default:
		this->sprite.setPosition(183.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	}
}

void Mobil2::initDirection()
{
	if (sprite.getPosition().x < 130) {
		Gerak::initDirection();
		direction.x = 0.85f;
	}
	else {
		Gerak::initDirection();
		direction.x = -0.85f;
	}
}

Mobil2::Mobil2()
{
	this->initVariables();
	this->initSprite();
	this->initDirection();
}

Mobil2::~Mobil2()
{
}

Mobil2::Mobil2(const Mobil2& n)
{
	this->direction = n.direction;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->time = n.time;
}

void Mobil2::update(bool die)
{
	updateAnimation();
	

	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}
}


int Mobil2::getType()
{
	return 0;
}
