#pragma once
#include "Gerak.h"
class Lawan :
	public Gerak
{
protected:
	virtual void initDirection() {};
	virtual void initVariables();
	virtual void initSprite()=0;
public:
	Lawan();
	~Lawan();
	Lawan(const Lawan& n);
	virtual void update(bool die) = 0;
	void render(RenderTarget& target);
	virtual int getType()=0;
	Clock& get_time();
};

