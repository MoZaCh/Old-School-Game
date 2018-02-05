#pragma once

#include "Functions.h"
#include "EnemyEncounter.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>





class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions

	void mainMenu();
	void initGame();
	void saveChars();
	void loadChars();
	void createChar();
	void travel();

	//Accerssors
	inline bool getPlaying() const { return this->playing; }
	//Modifiers
private:

	int choice;
	bool playing;

	//character
	int activeCharacter;
	std::vector<Character> characters;
	std::string saveFile;
};
