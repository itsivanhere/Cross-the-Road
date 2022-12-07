#pragma once
#include "Lawan.h"
class Mobil1 :
	public Lawan
{
protected:
	int randtime;
	float timermax, timer;
	void initVariables();
	void initSprite();
	void initDirection();
public:
	Mobil1();
	~Mobil1();
	Mobil1(const Mobil1& n);
	void update(bool die);
	int getType();
};

