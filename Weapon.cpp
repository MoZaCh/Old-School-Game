#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(int dmgMin, int dmgMax, std::string name, int lvl,
	int cost, int value, int rarity)
	:Item(name, lvl, cost, value, rarity)//calls item constructor from Item.cpp to get the values of the weapon
{
	this->dmgMax = dmgMax;
	this->dmgMin = dmgMin;

}


Weapon::~Weapon()
{
}

Weapon* Weapon::clone()const
{
	//function that returns a new copy of a virtual Item class clone
	return new Weapon(*this);//pointer to the Item's subclass Weapon

}

std::string Weapon::toString()
{
	std::string str = std::to_string(this->dmgMin) + " " + std::to_string(this->dmgMax);
	return str;
}
