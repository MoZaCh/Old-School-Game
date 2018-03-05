#include <iostream>
#include <string>
using namespace std;

class SpellClasses
{
// private variables are only available to methods in the class
private:
	int health;
	int attack;
	int defence;
  	int mana;
  	string equip;
 
// Public variables can be accessed by anything with access to the object
public:
  //getters
	int getHealth(){return health;}
	int getAttack(){return attack;}
	int getDefence(){return defence;}
  	int getMana(){return mana;}
  	string getEquip(){return equip;}
  //setters
	void setHealth(int HP){ health = HP; }
	void setAttack(int dmg){ attack = dmg; }
	void setDefence(int deff){ defence = deff; }
  	void setMana(int Mana){ mana = Mana; }
  	void setEquip(string eq){ equip = eq; }
 
	// Declare the constructor
	SpellClasses(int, int, int, int, string);
 
 
	// This method will be called by every class that inherits from SpellClasses
	void toString(); 
 
};

void SpellClasses::toString(){
 
	// Because the attributes were private in SpellClasses they 
	// must be retrieved by called the get methods
	cout << "Health: "<< this -> getHealth() << endl;
  	cout << "Attack: " << this -> getAttack() << endl;
  	cout << "Defence: " << this -> getDefence() << endl;
  	cout << "Mana: "<< this -> getMana()<< endl;
  	cout << "Equip: " << this -> getEquip()<<endl;
 
}


 
// A constructor is called when an object is created
SpellClasses::SpellClasses(int health, int attack, int defence,
                           int mana, string equip) {
  
  // This is used to refer to an object created of this class type
	this -> health = health;
	this -> attack = attack;
	this -> defence = defence;
  	this -> mana  = mana;
  	this -> equip = equip;
 
}

 
// We can inherit the variables and methods of other classes
class Mage : public SpellClasses{
 
	private:
		string greeting = "Mage is ready to fight!";
	public:
		void getGreeting() { cout << greeting << endl; }
 
		// Declare the constructor
		Mage(int, int, int, int, string);

 
};
 
// Mage constructor passes the right attributes to the superclass constructor
Mage::Mage(int health, int attack, int defence, int mana, 
         string equip) : 
SpellClasses(health, attack, defence, mana, equip){
 
	this -> greeting = greeting;
 
}

class Priest : public SpellClasses{
  private:
     string greeting = "Priest is ready to fight!";
  
  public:
     void getGreeting(){cout << greeting << endl;}
       
     //Declare the constructor
     Priest(int, int, int, int, string);
  
};

// Priest constructor passes the right attributes to the superclass constructor
Priest::Priest(int health, int attack, int defence, int mana, 
         string equip) : 
SpellClasses(health, attack, defence, mana, equip){
 
	this -> greeting = greeting;
 
}

class Necromancer : public SpellClasses{
  private:
     string greeting = "Necromancer is ready to fight!";
     //DO NOT FORGET TO SWITCH MANA WITH HEALTH-USING LATER
  
  public:
     void getGreeting(){cout << greeting << endl;}
       
     //Declare the constructor
     Necromancer(int, int, int, int, string);
};

// Necromancer constructor passes the right attributes to the superclass constructor
Necromancer::Necromancer(int health, int attack, int defence, int mana, 
         string equip) : 
SpellClasses(health, attack, defence, mana, equip){
 
	this -> greeting = greeting;
}
 

int main(){
 
	// Demonstrate the inheriting class Mage
	Mage MageObject(200, 800, 150, 500, "Staff");
  	//Test the getGreeting method that will be called
	MageObject.getGreeting();
	// Test the toString method that will be called 
	MageObject.toString();
  cout<< "--------" << endl;
  
  	Priest PriestObject(100, 700, 250, 600, "Talisman");
  	PriestObject.getGreeting();
  	PriestObject.toString();
  cout << "----------"<< endl;
  
  	Necromancer NecrObject(300, 600, 350, 400, "Staff");
  	NecrObject.getGreeting();
  	NecrObject.toString();
  
  return 0;
}