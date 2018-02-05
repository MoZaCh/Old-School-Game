#pragma once

#include <iostream>
#include <iomanip>
#include <string>


class Item
{
public:
	Item(std::string name = "NONE", int level = 0,
		int cost = 0,
		int value = 0,
		int rarity = 0
		);
	virtual ~Item();

	//Virtual

	virtual Item* clone() const = 0;//makes a pure virtual Item clone in order to create an item it is necessary to create a child clas like weapon or armour
	// NOTE: Makes the copy of an Item in to the inventory by itself, if there wount be this virual function, we had to make another function to identify what kind of item is this
	// NOTE: Virtual item clone makes it easier to build up inventory of items

	//TEST

	inline std::string printTest() const { return this->name; }

private:
	std::string name;//item name
	int cost;//for buying
	int value;//for selling
	int rarity;//rarity of an item
	int lvl;//item level

	//Modifiers

	//Accessors
	inline const std::string& getName() const { return this->name; }
	inline const int& getLvl() const { return this->lvl; }
	inline const int& getCost() const { return this->cost; }
	inline const int& getValue() const { return this->value; }
	inline const int& getRarity() const { return this->rarity; }
};

