#pragma once
#include "Lawan.h"
class Penghalang :
	public Lawan
{
protected:
	void initSprite();
public:
	Penghalang(); 
	~Penghalang();
	Penghalang(const Penghalang& n);
	void update(bool die);
	int getType();
};

