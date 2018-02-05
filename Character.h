#pragma once

#include "Inventory.h"
#include "Enemy.h"


class Character
{

private:

	Inventory inventoryOwn;//creating a private inventory for each character with private weapons and armour
	Weapon weapon_axe;//Warrior
	Weapon weapon_greateSword;//Warrior
	Weapon weapon_staff;//Necromancer
	Weapon weapon_spellbook;//Mage
	Weapon weapon_talisman;//Priest
	Weapon weapon_bow;//Hunter
					  //Armour
	Armour armour_helm;
	Armour armour_chest;
	Armour armour_gloves;
	Armour armour_legs;
	Armour armour_boots;

	int gold;


	std::string name;
	int lvl;
	int exp;
	int expNext;
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int dmgMin;
	int dmgMax;
	int def;

	double xCoor;
	double yCoor;
	int distanceOverall;

	int statsPts;
	int skillPts;

	int str;
	int dex;
	int intel;
	int vit;
public:
	Character();
	virtual ~Character();
	
	//Functions
	void initialize(std::string name);
	void getInfoString() const; //function to get player stats in string
	void lvlUP();
	std::string getAsString() const;

	//Accessors
	inline const double& getX() const { return this->xCoor; }
	inline const double& getY() const { return this->yCoor; }
	inline const std::string& getName() const { return this->name; }
	inline const int& getLvl() const { return this->lvl; }
	inline const int& getXp() const { return this->exp; }
	inline const int& getXpNext() const { return this->expNext; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getHPM() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDMGMin() const { return this->dmgMin; }
	inline const int& getDMGMax() const { return this->dmgMax; }
	inline const int& getDef() const { return this->def; }

	inline const int& getDist() const { return this->distanceOverall; }
	//Modifiers 
	inline void setDistOverall(const int& distance) { this->distanceOverall = distance; }
	inline void travel() { this->distanceOverall++; }
	inline void gainXp(const int exp) { this->exp += exp; }


};

