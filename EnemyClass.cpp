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
    cout<<"1) Execute  3) Charge  4) Reflect "<<endl;
  }

	void toEnemyString() {
		cout << "Health: " << this->getEnemyHealth() 
		 << " Attack: " << this->getEnemyAttack() 
		 << " Defence: " << this->getEnemyDefence() 
		 << " Weapon: " << this->getEnemyWeapon() << endl;

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











