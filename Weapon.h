#pragma once
#include"Item.h"



class Weapon:
	public Item //includes all public attributes form "Item" class
{
public:
	Weapon(int dmgMin = 0, int dmgMax = 0, std::string name = "None",
	int lvl = 0, int cost = 0, int value = 0, int rarity = 0
	);
	virtual ~Weapon();

	//Functions 
	std::string toString();
	//Virtual
	virtual Weapon* clone()const;

private:
	int dmgMin;
	int dmgMax;
};

