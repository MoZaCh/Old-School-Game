#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
	this->cap = 5;
	this->itemNum = 0;
	this->itemArr = new Item*[cap];
	this->initialize();
}


Inventory::~Inventory()
{
	//deletes dynamic array
	for (size_t i = 0; i < this->itemNum; i++)
	{
		delete this->itemArr[i];
	}

	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory &obj)
{
	//creates a copy of an old item array. Otherwise it would be just a pointer to the old item array, which result in having one inventory for all characters
	this->cap = obj.cap;
	this->itemNum = obj.itemNum;
	this->itemArr = new Item*[this->cap];

	for (size_t i = 0; i < this->itemNum; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(this->itemNum);
}

Item& Inventory::operator[](const int index)
{
	//returns an item if the index is correct
	if (index < 0 || index >= this->itemNum)//checks if the Item is within the array of items
		throw ("BAD INDEX");
	return *this->itemArr[index];//dereferancing the referance in order to return the item and not the pointer to the item

	

}

void Inventory::expand()
{
	this->cap *= 2;

	Item **tempArr = new Item*[this->cap];//temporary array for 2x the size of the capacty of the inventory

	for (size_t i = 0; i < this->itemNum; i++)
	{
		tempArr[i] = this->itemArr[i];//adds the items from the temporary array to the new, expanded, array
	}

	
	delete[] this->itemArr;//deletes the whole old array(with old items)
	
	this->itemArr = tempArr;//from tmp array copies items to premanent array

	this->initialize(this->itemNum);//initializes the rest of the unused positions

}
void Inventory::initialize(const int from)
{
	//pointer nullification, to resize the inventory space after the items has been added or removed
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	}

}


void Inventory::itemAdd(const Item &item)
{
	//expands inventortory if there is no more space in it
	//adds new item to the inventory
	if (this->itemNum >= this->cap)
	{
		expand();
	}
	this->itemArr[this->itemNum++] = item.clone();

}
void Inventory::itemRem(int index)
{


}
