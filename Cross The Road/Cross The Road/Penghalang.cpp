#include "Penghalang.h"

void Penghalang::initSprite()
{
	texture.loadFromFile("images/tree.png");
	this->sprite.setTexture(texture);
	this->sprite.setScale(0.7f, 0.7f);
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(225.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	case 1:
		this->sprite.setPosition(100.f,50.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	default:
		this->sprite.setPosition(190.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	}
}

Penghalang::Penghalang()
{
	Gerak::initDirection();
	this->initSprite();

}

Penghalang::~Penghalang()
{
}

Penghalang::Penghalang(const Penghalang& n)
{
	this->texture = n.texture;
	this->sprite = n.sprite;
	this->direction = n.direction;
	this->time = n.time;
}

void Penghalang::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}
}

int Penghalang::getType()
{
	return 2;
}


