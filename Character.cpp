#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	this->xCoor = 0.0;
	this->yCoor = 0.0;
	this->distanceOverall = 0;

	this->gold = 0;

	this->name = "";
	this->lvl = 0;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->dmgMin = 0;
	this->dmgMax = 0;
	this->def = 0;

	this->statsPts = 0;
	this->skillPts = 0;

	this->str = 0;
	this->dex = 0;
	this->intel = 0;
	this->vit = 0;

}


Character::~Character()
{
}

//Functions
void Character::initialize(const std::string name)
{
	//initializing player stats

	this->xCoor = 0.0;
	this->yCoor = 0.0;

	this->gold = 200;

	this->str = 3;
	this->dex = 3;
	this->intel = 3;
	this->vit = 3;

	this->name = name;
	this->lvl = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3)*((pow(lvl, 3) -
		6 * pow(lvl, 2)) +
		17 * lvl - 12)); //this gives unlimited lvl cap

	this->hpMax = (this->vit *2) * (this->str/2);
	this->hp = hpMax;
	this->staminaMax = this->vit + (this->str/2) + (this->dex/3);
	this->stamina = this->staminaMax;
	this->dmgMin = str;
	this->dmgMax = str+4;
	this->def = this->dex * (this->intel/2);
	this->statsPts = 0;
	this->skillPts = 0;

	
}

void Character::getInfoString() const
{
	std::cout << "***CHARACTER INFO***" << std::endl;
	std::cout << "# Name: " << this->name << std::endl;
	std::cout << "# LVL: " << this->lvl << std::endl;
	std::cout << "# EXP: " << this->exp << std::endl;
	std::cout << "# Exp left to lvl up: " << this->expNext;

	std::cout << std::endl;

	std::cout << "# HP: " << this->hp << "/" << this->hpMax << std::endl;
	std::cout << "# Stamina: " << this->stamina << "/" << this->staminaMax << std::endl;

	std::cout << std::endl;

	std::cout << "# str: " << this->str << std::endl;
	std::cout << "# dex: " << this ->dex << std::endl;
	std::cout << "# int: " << this->intel << std::endl;
	std::cout << "# vit: " << this->vit << std::endl;

	std::cout << std::endl;
	
	std::cout << "#DMG: " << this->dmgMin << " - " << this->dmgMax << std::endl;
	std::cout << "#DEF: " << this->def << std::endl;
	std::cout << std::endl;
}

void Character::lvlUP()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->lvl++;
		this->expNext =static_cast<int>((50 / 3)*((pow(lvl, 3) -
			6 * pow(lvl, 2)) + 
			17 * lvl - 12));

		this->statsPts++;
		this->skillPts++;
	}
	else
	{
		std::cout << "YOU CANNOT LEVEL UP YET. GET MORE XP" << "\n\n";
	}
}

std::string Character::getAsString() const
{
	//function that takes char attributes and sends them as a string
	//created for saving char data
	return std::to_string(xCoor) + " "
		+ std::to_string(yCoor) + " "
		+ name + " "
		+ std::to_string(lvl) + " "
		+ std::to_string(exp) + " "
		+ std::to_string(hp) + " "
		+ std::to_string(stamina) + " "
		+ std::to_string(def) + " "
		+ std::to_string(statsPts) + " "
		+ std::to_string(skillPts) + " "
		+ std::to_string(str) + " "
		+ std::to_string(dex) + " "
		+ std::to_string(intel) + " "
		+ std::to_string(vit);

}
