#include "Objek.h"

Objek::Objek(){}

Objek::Objek(const Objek& n){}

void Objek::updateAnimation()
{
	if (time.getElapsedTime().asSeconds() > 0.2f) {
		if (this->intRect.left >= maxSize) {
			this->intRect.left = 0;
		}
		else {
			this->intRect.left += plusWidth;
		}
		this->sprite.setTextureRect(this->intRect);
		time.restart();
	}
}

Sprite& Objek::getSprite()
{
	return sprite;
}

Texture& Objek::getTexture()
{
	return texture;
}

IntRect& Objek::getIntRect()
{
	return intRect;
}

void Objek::setMaxSize(int x)
{
	maxSize = x;
}

void Objek::setplusWidth(int x)
{
	plusWidth = x;
}
