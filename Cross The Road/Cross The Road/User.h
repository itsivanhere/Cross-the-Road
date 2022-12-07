#pragma once
#include "Gerak.h"
class User :
	public Gerak
{
protected:
	//variabel
	int keyApressed, keyDpressed;

	//init
	void initVariables();
	void initSprite();
public:
	User();
	~User();
	User(const User& n);
	void update(bool die);
	void render(RenderTarget& target);
};

