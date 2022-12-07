#pragma once
#include "Lawan.h"
class Mobil2 :
	public Lawan
{
protected:
	void initVariables();
	void initSprite();
	void initDirection();
public:
	Mobil2(); 
	~Mobil2(); 
	Mobil2(const Mobil2& n);
	void update(bool die) ;
	int getType();
};

