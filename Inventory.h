#pragma once


#include "Weapon.h"
#include "Armour.h"


class Inventory
{
public:
	Inventory();
	~Inventory();
	Inventory(const Inventory &obj);//copy constructor, to put new Items into another array, if there wount be this copy constructor, then the new items would be pointed into the same memory of an old items
	inline int size()const { return this->itemNum; }
	Item& operator[](const int index);//sign &(referance) returns refernce to an items, this is used instead of "get" function
	inline void printTest() const
	{
		//print the whole inventory to test if the temAdd and expand functions are working
		for (size_t i = 0; i < this->itemNum; i++)
		{
			std::cout << this->itemArr[i]->printTest() << std::endl;
		}


	}

	void itemAdd(const Item & item);//function to add items in to the inventory
	void itemRem(int index);//function to remove items from inventory
private:
	void expand();
	void initialize(const int from = 0);
	Item **itemArr;
	int cap;//capacity of the inventory
	int itemNum;//number of items in the inventory

};

