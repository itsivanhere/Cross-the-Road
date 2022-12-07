#pragma once
#include "Gerak.h"
class Koin :
	public Gerak
{
protected:
	void initVariables();
	void initSprite();
	
public:
	Koin(); 
	~Koin();
	Koin(const Koin& n);
	void update(bool die);
	void render(RenderTarget &target);
	int getType();
};

