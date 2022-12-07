#pragma once
#include "Koin.h"
class Koin1 :
	public Koin
{
protected:
	void initSprite();
public:
	Koin1();
	~Koin1();
	Koin1(const Koin1& n);
	int getType();
};

