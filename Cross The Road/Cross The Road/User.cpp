#include "User.h"

void User::initVariables()
{
	intRect.top = 0;
	intRect.left = 0;
	intRect.width = 643;
	intRect.height = 936;
	keyApressed = 0; keyDpressed = 0;

	//subject to change
	maxSize = 9338;
	plusWidth = 936;
}


void User::initSprite()
{
	
	texture.loadFromFile("images/spritesheet.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(this->intRect);
	sprite.setPosition(100.f, 225.f);
	sprite.setScale(0.21f, 0.2f);
}


User::User()
{
	this->initVariables();
	this->initSprite();
	initDirection();
}


User::~User() {}


User::User(const User& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}


void User::update(bool die)
{
	this->updateAnimation();
	if (!die) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (!keyApressed) {
				keyApressed = 1;
				keyDpressed = 0;
				this->sprite.move(-40.f, 0.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (!keyDpressed) {
				keyDpressed = 1;
				keyApressed = 0;
				this->sprite.move(40.f, 0.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (!keyDpressed) {
				keyDpressed = 1;
				keyApressed = 0;
				this->sprite.move(0.f, -40.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (!keyDpressed) {
				keyDpressed = 1;
				keyApressed = 0;

				this->sprite.move(0.f, 40.f);
			}
		}
		else {
			keyApressed = 0;
			keyDpressed = 0;
		}

		//out of range check
		if (this->sprite.getPosition().x < -10.f) {
			this->sprite.setPosition(Vector2f(-10.f, this->sprite.getPosition().y));
		}
		if (this->sprite.getPosition().x > 220.f) {
			this->sprite.setPosition(Vector2f(220.f, this->sprite.getPosition().y));
		}
		if (this->sprite.getPosition().y > 530.f) {
			this->sprite.setPosition(Vector2f(this->sprite.getPosition().x,530.f));
		}
		if (this->sprite.getPosition().y < 0.f) {
			this->sprite.setPosition(Vector2f(this->sprite.getPosition().x,0.f));
		}
	}
}


void User::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
