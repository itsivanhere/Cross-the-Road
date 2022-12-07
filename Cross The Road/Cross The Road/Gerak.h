#pragma once
#include "Objek.h"
class Gerak :
	public Objek
{
protected:
	Vector2f direction;
	virtual void initDirection();
public:
	void setDirection(float x,float y);
};

