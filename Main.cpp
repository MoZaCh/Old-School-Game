#include "stdafx.h"
#include "Game.h"
#include "Functions.h"


int main()
{
	srand(time(NULL));

	Game game;
	game.initGame();
	

	while (game.getPlaying())
	{
		game.mainMenu();
		

	}



	return 0;

	/*Inventory inv;
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());	//this tests if the inventory is working correctl
	inv.itemAdd(Item());	//checking itemAdd function
	inv.itemAdd(Item());	//checking if the inventory expands if there are more items than there are capacity of the inventory
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());
	inv.itemAdd(Item());

	inv.printTest();*/



}
