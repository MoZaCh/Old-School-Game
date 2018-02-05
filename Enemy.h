#pragma once
#include <stdlib.h>
#include <string>


class Enemy
{
private:
	int lvl;
	int hp;
	int hpMax;
	int def;
	float drop;
	int dmgMin;
	int dmgMax;
public:
	Enemy(int lvl = 0);
	virtual ~Enemy();
	inline bool alive(){ return this->hp > 0; }
	std::string getAsString()const;
	inline void takeDmg(int dmg) {this->hp -= dmg; }
	inline int getDmg() const {return rand() % this->dmgMax - this->dmgMin; }
	inline int getXP() const { return this->lvl * 100; }
};

