#pragma once
#include "Character.h"

class EnemyEncounter
{
private:

public:
	EnemyEncounter();
	virtual ~EnemyEncounter();
	void encounter(Character &character);
};

