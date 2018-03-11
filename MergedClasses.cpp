#include <iostream>
#include <string>
#include <fstream>

#include "libsqlite.hpp"
using namespace std;

//Updata class type in DB
void updateClassSQL(string classType, int userId)
{
  sqlite::sqlite db("testdb.db"); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("UPDATE users SET class = (?) "
               "WHERE id = ?;"); //SQL command
  cur->prepare(); //Sends to database
  cur->bind(1, classType);
  cur->bind(2, userId);
  cur->step();
}


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
		string greeting = "Class Mage Picked!\n";
	public:
		void getGreeting() { cout << greeting << endl; }
		
		 void spells() {
      cout<< "Which spell to use?\n\n1. Frostbolt (250 mana) \n2. Blink (180 mana) \n3. DeepFreeze (300 mana)\n"<<endl;
			 
	}
 
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
     string greeting = "Class Priest Picked!\n";
  
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
     string greeting = "Class Necromancer Picked!\n";
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

class Warrior : public SpellClasses{
 
  private:
    string greeting = "Class Warrior Picked!\n";
  public:
    void getGreeting(){cout<< greeting<<endl;}
  
  //Declare the constructor
    Warrior(int, int, int, int, string);
 
  
};

Warrior::Warrior(int health, int attack, int defence, int mana, 
         string equip):
  SpellClasses(health, attack, defence, mana, equip){
    
    this-> greeting=greeting;
    
  }

class Hunter : public SpellClasses{
  
  private:
    string greeting= "Class Hunter Picked!\n";
  public:
    void getGreeting(){cout<<greeting<<endl;}
  
  //constructor
    Hunter(int, int, int, int, string);
};

Hunter::Hunter(int health, int attack, int defence, int mana, 
         string equip):
  SpellClasses(health, attack, defence, mana, equip){
    
    this->greeting=greeting;
  }
 
int classes(int userId)
{
    Mage MageObject(200, 800, 150, 500, "Staff"); //Stating Variables
    Priest PriestObject(100, 700, 250, 600, "Talisman");//Stating Variables
    Necromancer NecrObject(300, 600, 350, 400, "Staff");//Stating Variables
    Warrior warriorObject(800, 900, 600, 0, "Axe");//Stating Variables
    Hunter hunterObject(700, 1000, 400, 0, "Bow");//Stating Variables
    
    string class1;
    
    class1:
    class2:
    cout << endl;
    cout << "1. Mage\n2. Priest\n3. Necromancer\n4. Warrior\n5. Hunter" << endl; //Gives User Option To Choose
    
    cout << endl;
    
    cin >> class1;
    cout << endl;
     if (class1 == "1")
     {
	cout << "Stats For Mage." << endl;
         cout << endl;
         
         MageObject.toString(); //Prints stats for mage
         
         cout << endl;
    cout << "Are You Sure?" << endl;
         
         Confirm:
         
         string confirm;
         
         cout << "Y/N" << endl; //Confirms Choice
         cout << endl;
         cin >>confirm;
         cout << endl;
         if (confirm == "Y" || confirm == "y")
         {
           string classType = "Mage";
           updateClassSQL(classType,userId);
         }
         else if (confirm == "N" || confirm == "n")
         {
             confirm.clear(); //Clears Variable
             goto class2; // Loops Back
         }
         else
         {
             cout << "Invaid Input, Must be Y or N!" << endl;
             confirm.clear();
             goto Confirm;
         }
         
    
	MageObject.getGreeting(); //Prints Greeting Message
         
         ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt");
  myfile << "Mage\n";
  myfile.close();
  return 0;
	
         
         
     }
        else if (class1 == "2")
        {
            cout << "Stats For Priest." << endl;
         cout << endl;
         
         PriestObject.toString(); //Prints stats
         
         cout << endl;
            cout << "Are You Sure?" << endl;
         
         Confirm1:
         
         string confirm;
         
         cout << "Y/N" << endl;
         cout << endl;
         cin >>confirm;
         cout << endl;
         if (confirm == "Y" || confirm == "y")
         {
           string classType = "Priest";
           updateClassSQL(classType,userId);
         }
         else if (confirm == "N" || confirm == "n")
         {
             confirm.clear();
             goto class2;
         }
         else
         {
             cout << "Invaid Input, Must be Y or N!" << endl;
             confirm.clear();
             goto Confirm1;
         }
         	
  	PriestObject.getGreeting();
  	         ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt");
  myfile << "Priest\n";
  myfile.close();
  return 0;
	
            
  
        }
    else if (class1 == "3")
    {
        cout << "Stats For Necromancer." << endl;
         cout << endl;
         
         NecrObject.toString(); //Prints stats
         
         cout << endl;
        cout << "Are You Sure?" << endl;
         
         Confirm2:
         
         string confirm;
         
         cout << "Y/N" << endl;
         cout << endl;
         cin >>confirm;
         cout << endl;
         if (confirm == "Y" || confirm == "y")
         {
           string classType = "Necromancer";
           updateClassSQL(classType,userId);
         }
         else if (confirm == "N" || confirm == "n")
         {
             confirm.clear();
             goto class2;
         }
         else
         {
             cout << "Invaid Input, Must be Y or N!" << endl;
             confirm.clear();
             goto Confirm2;
         }
    
  	NecrObject.getGreeting();
  	         ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt");
  myfile << "Necromancer\n";
  myfile.close();
  return 0;
	
        
    }
    else if (class1 == "4")
    {
        cout << "Stats For Warrior." << endl;
         cout << endl;
         
         warriorObject.toString(); //Prints stats
         
         cout << endl;
        cout << "Are You Sure?" << endl;
         
         Confirm3:
         
         string confirm;
         
         cout << "Y/N" << endl;
         cout << endl;
         cin >>confirm;
         cout << endl;
         if (confirm == "Y" || confirm == "y")
         {
           string classType = "Warrior";
           updateClassSQL(classType,userId);
         }
         else if (confirm == "N" || confirm == "n")
         {
             confirm.clear();
             goto class2;
         }
         else
         {
             cout << "Invaid Input, Must be Y or N!" << endl;
             confirm.clear();
             goto Confirm3;
         }

    warriorObject.getGreeting();
             ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt");
  myfile << "Warrior\n";
  myfile.close();
  return 0;
	
         
     }
        else if (class1 == "5")
        {
            cout << "Stats For Hunter." << endl;
         cout << endl;
         
         hunterObject.toString(); //Prints stats
         
         cout << endl;
            cout << "Are You Sure?" << endl;
         
         Confirm4:
         
         string confirm;
         
         cout << "Y/N" << endl;
         cout << endl;
         cin >>confirm;
         cout << endl;
         if (confirm == "Y" || confirm == "y")
         {
           string classType = "Hunter";
           updateClassSQL(classType,userId);   
         }
         else if (confirm == "N" || confirm == "n")
         {
             confirm.clear();
             goto class2;
         }
         else
         {
             cout << "Invaid Input, Must be Y or N!" << endl;
             confirm.clear();
             goto Confirm4;
         }
          
          hunterObject.getGreeting();
                   ofstream myfile; //Creates txt doc of class chosen
  myfile.open ("classChoice.txt");
  myfile << "Hunter\n";
  myfile.close();
  return 0;
	
            
  
        }
      else //Error Test
      {
          cout << "Invalid input! Must answer with 1, 2, 3, 4 or 5" << endl;
          class1.clear();
          goto class1;
      }
  
  return 0;
}
