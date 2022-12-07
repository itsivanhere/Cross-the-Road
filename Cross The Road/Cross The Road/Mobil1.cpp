#include "Mobil1.h"

void Mobil1::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 655;
	intRect.width = 1372;
	maxSize = 4116;
	plusWidth = 1372;
	randtime = 1;
	timermax = 50.f;
	timer = 0.f;
}

void Mobil1::initSprite()
{
	texture.loadFromFile("images/mobil.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(this->intRect);
	sprite.setScale(0.05f, 0.05f);
	int rando = rand() % 3;  // 3 posisi awal
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(60.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	case 1:
		this->sprite.setPosition(120.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	default:
		this->sprite.setPosition(183.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	}
}

void Mobil1::initDirection()
{
	if (sprite.getPosition().x == 60) {
		Gerak::initDirection();
		direction.x = 3.4f;
	}
	else if (sprite.getPosition().x == 120) {
		int rando = rand() % 2;
		switch (rando)
		{
		case 0:
			Gerak::initDirection();
			direction.x = 3.4f;
			 break;
		default:
			Gerak::initDirection();
			direction.x = -3.4f;
			break;
		}
	}
	else {
		Gerak::initDirection();
		direction.x = -3.4f;
	}
}

Mobil1::Mobil1()
{
	this->initDirection();
	this->initSprite();
	this->initVariables();
}

Mobil1::~Mobil1()
{

}

Mobil1::Mobil1(const Mobil1& n)
{
	this->direction = n.direction;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->time = n.time;
}

void Mobil1::update(bool die)
{
	updateAnimation();


	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}

	
}

int Mobil1::getType()
{
	return 1;
}

