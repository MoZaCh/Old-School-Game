#pragma once
#include <iostream>
#include <string>
using namespace std;

class Enemy {
private:
	int health;
	int attack;
	int defence;
	string weapon;
public:
	//getters
	int getEnemyHealth() { return health; }
	int getEnemyAttack() { return attack; }
	int getEnemyDefence() { return defence; }
	string getEnemyWeapon() { return weapon; }
   

	Enemy(int, int, int, string);
  
  void abilities(){
    cout<<"- Execute  \n- Charge  \n- Reflect "<<endl;
  }

	void toEnemyString() {
		cout << "Health: " << this->getEnemyHealth() << endl;
		cout << "Attack: " << this->getEnemyAttack() << endl;
		cout << "Defence: " << this->getEnemyDefence() << endl;
		cout << "Weapon: " << this->getEnemyWeapon() << endl;

	}
};

// A constructor is called when an object is created
Enemy::Enemy(int health, int attack, int defence,
	string weapon) {
	// This is used to refer to an object created of this class type  
	this->health = health;
	this->attack = attack;
	this->defence = defence;
	this->weapon = weapon;
}











