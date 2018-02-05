#include "stdafx.h"
#include "Game.h"
#include "Functions.h"



Game::Game()
{
	//functions in game menu
	choice = 0;
	playing = true;
	activeCharacter - 0;
	saveFile = "saveFiles.txt";

}


Game::~Game()
{

}


//Functions

void Game::initGame()
{
	
	createChar();//function takes string input fom user and uses it as a name of the new player
	saveChars();
	
}

void Game::mainMenu()
{
	//game main menu

	if (this->characters[activeCharacter].getXp() >= this->characters[activeCharacter].getXpNext())
	{
		std::cout << "YOU CAN NOW LEVEL UP \n\n";

	}

	std::cout << "MAIN MENU" << std::endl;
	std::cout << "0: QUIT" << std::endl;
	std::cout << "1: TRAVEL" << std::endl;
	std::cout << "2: LEVEL UP" << std::endl;
	std::cout << "3: SHOP" << std::endl;
	std::cout << "4: REST" << std::endl;
	std::cout << "5: CHARACTER INFO" << std::endl;
	std::cout << "6: Create new Character" << std::endl;
	std::cout << "7: Save" << std::endl;
	std::cout << "8: Load" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Choice: ";

	std::cin >> choice;

	std::cout << std::endl;


	switch (choice)
	{
	case 0:
		playing = false; //quits the game
		break;
	case 1:
		travel();
		break;
	case 2:
		characters[activeCharacter].lvlUP();
		break;
	case 5:
		characters[activeCharacter].getInfoString(); //prints the information about the player in to the console
		break;
	case 6:
		std::cin.ignore();//ignores the line where user inputs menu choice
		createChar();
		saveChars();
		
		break;
	case 7:
		saveChars();


		break;
	case 8:
		loadChars();


		break;
	default:
		break;
	}

}

void Game::createChar()
{
	//function to create new character
	std::string name;
	std::cout << "ENTER CHARACTER NAME: ";
	
	std::getline(std::cin, name);
	

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;//active char is the last one in the array, because it is the latest one which was created
	characters[activeCharacter].initialize(name);


}

void Game::saveChars()
{
	std::ofstream fd(saveFile);
	if (fd.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			fd << characters[i].getAsString() << "\n";

		}
	}
	fd.close();
}

void Game::loadChars()
{


}

void Game::travel()
{
	this->characters[activeCharacter].travel();

	EnemyEncounter enc;
	enc.encounter(this->characters[activeCharacter]);

}
