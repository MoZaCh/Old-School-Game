#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(int lvl)
{
	this->lvl = lvl;
	this->hpMax = lvl * 10;
	this->hp = this->hpMax;
	this->def = rand() % 100;
	this->drop = rand() % 100;
	this->dmgMin = lvl * 2;
	this->dmgMax = lvl * 3;
	
}


Enemy::~Enemy()
{
}
std::string Enemy::getAsString() const
{
	return "Level: " + std::to_string(this->lvl) + "\n" +
		"HP: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"DMG: " + std::to_string(this->dmgMin) + " - " + std::to_string(this->dmgMax) + "\n" +
		"Defence: " + std::to_string(this->def) + "\n" +
		"Loot drop chance: " + std::to_string(this->drop) + "\n";
}
