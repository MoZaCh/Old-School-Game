#pragma once
#include"Item.h"



class Armour:
	public Item 
{
private:
	int part;
	int def;

	
public:
	Armour(int part = 0, int def = 0, std::string name = "None",
		int lvl = 0, int cost = 0, int value = 0, int rarity = 0
	);
	virtual ~Armour();

	//Functions
	std::string toString();
	//Virtual
	virtual Armour* clone() const;
};



