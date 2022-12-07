#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<ctime>;
using namespace sf;
class Objek
{
protected:
	//variabel
	int maxSize;//untuk mengetahui brp width max dari png sebelum reset to 0
	int plusWidth;//untuk plus inrect.left

	//sfml variabel
	Sprite sprite;
	Texture texture;
	IntRect intRect;
	Clock time;
	virtual void initVariables() = 0;//fluid emngikuti class polymorph
	virtual void initSprite()=0;
	
public:
	Objek();
	Objek(const Objek&n);
	void updateAnimation();
	virtual void update(bool die) = 0;
	virtual void render(RenderTarget& target) = 0;
	Sprite& getSprite();
	Texture& getTexture();
	IntRect& getIntRect();
	void setMaxSize(int x);
	void setplusWidth(int x);
};

