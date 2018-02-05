#include "stdafx.h"
#include "Armour.h"


Armour::Armour(int part, int def, std::string name, int lvl,
	int cost, int value, int rarity)
	:Item(name, lvl, cost, value, rarity)//calls item constructor from Item.cpp to get the values of the weapon
{
	this->part = part;
	this->def = def;

}


Armour::~Armour()
{
}

Armour* Armour::clone() const
{
	return new Armour(*this);
}

std::string Armour::toString()
{
	std::string str = std::to_string(this->part) + " " + std::to_string(this->def);
	return str;
}
