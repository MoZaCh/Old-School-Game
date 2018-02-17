#include <iostream>
#include <string>
using namespace std;

class AbilityClasses{
  private:
    int health;
    int attack;
    int defence;
    string weapon;
  public:
  //getters
    int getHealth(){return health;}
    int getAttack(){return attack;}
    int getDefence(){return defence;}
    string getWeapon(){return weapon;}
  
 //Declare the constructor 
  AbilityClasses(int, int, int, string);
  
  void toString();
    
};

void AbilityClasses::toString(){
  cout<< "Health: "<< this->getHealth()<<endl;
  cout<< "Attack: "<< this->getAttack()<<endl;
  cout<< "Defence: "<< this-> getDefence()<<endl;
  cout<< "Weapon: " << this-> getWeapon()<<endl;
  
}

// A constructor is called when an object is created
AbilityClasses::AbilityClasses(int health, int attack, int defence,
                              string weapon){
// This is used to refer to an object created of this class type  
  this->health=health;
  this->attack=attack;
  this->defence=defence;
  this->weapon=weapon;
}

class Warrior : public AbilityClasses{
 
  private:
    string greeting = "Warrior is ready to fight!";
  public:
    void getGreeting(){cout<< greeting<<endl;}
  
  //Declare the constructor
    Warrior(int, int, int, string);
 
  
};

Warrior::Warrior(int health, int attack, int defence, string weapon):
  AbilityClasses(health, attack, defence, weapon){
    
    this-> greeting=greeting;
    
  }

class Hunter : public AbilityClasses{
  
  private:
    string greeting= "Hunter is ready to fight!";
  public:
    void getGreeting(){cout<<greeting<<endl;}
  
  //constructor
    Hunter(int, int, int, string);
};

Hunter::Hunter(int health, int attack, int defence, string weapon):
  AbilityClasses(health, attack, defence, weapon){
    
    this->greeting=greeting;
  }


int main(){
  Warrior warriorObject(800, 900, 600, "Axe");
  warriorObject.getGreeting();
  warriorObject.toString();
  
  Hunter hunterObject(700, 1000, 400, "Bow");
  hunterObject.getGreeting();
  warriorObject.toString();
  
  
  return 0;
}
