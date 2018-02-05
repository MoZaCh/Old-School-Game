#include "stdafx.h"
#include "Item.h"


Item::Item(std::string name, int cost, int value, int rarity, int lvl)
{
	this->name = "NONE";
	this->cost = 0;
	this->value = 0;
	this->rarity = 0;
	this->lvl = 0;

}


Item::~Item()
{
}
