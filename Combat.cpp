#include <iostream>
#include <string>
#include <unistd.h>
#include "EnemyClass.cpp"
#include "Main_Menu.cpp"
#include "SpellClasses.cpp"

//these two for random number function generator
#include <cstdlib> 
#include <ctime> 


using namespace std;

int randomNumber(){                       
  srand((unsigned)time(0)); 
  int random_integer = rand(); 
  return random_integer;
  /* The following code will seed the generator with the system time and then output a single random number, which will be different each time we run the program.
    In another words, the first line is neccesary for generating a different number, or rather different sequence of numbers */
}
int main(){
 Mage mageObj(1200,1300,150,1500,"Staff");
  Enemy enemyObj(2000,1500,500,"Axe");
  
 cout<< "---------------You've entered battle---------------\n"<<endl;
 cout<< "YOUR STATS AND SPELLS: "<<endl;
 mageObj.toString();
 cout<< "1) Frostbolt  2) Blink 3) Deep Freeze"<<endl;
  
 cout<< "\nENEMY'S STATS AND ABILITIES: "<<endl;
 enemyObj.toEnemyString();
 cout<< "1) Execute  2) Mortal Strike  3) Charge  4) Reflect \n"<<endl;
  
  
 //getting values from Mage object
 int mageHealth = mageObj.getHealth();
 int mageMana = mageObj.getMana();
 int mageAttack = mageObj.getAttack();
 int mageDeffence = mageObj.getDefence();
 //getting values from Enemy object
 int enemyHealth = enemyObj.getEnemyHealth();
 int enemyAttack = enemyObj.getEnemyAttack();
 int enemyDefence = enemyObj.getEnemyDefence();
  
 //will be used to prevent using reflect more than twice by the enemy
 int reflectCounter = 0;  
 
 
 cout<<"-------------------LET THE BATTLE BEGIN!!!-------------------"<<endl; 
 cout<< "You are standing in the arena. The distance between you and your \nenemy is just a few meters. "<<endl;
 cout<< "Remember only one of you will walk out of this alive."<<endl;
  
  
    Start:
  char choice;
  mageObj.spells();
  cin>>choice;
    switch (choice){
    
  case '1': //Frostbolt
       randomNumber();
        
        if(enemyHealth<=0){
          cout<<"You have successfully killed your enemy!"<<endl;
          cout<<"Do you wish to go back to Main Menu? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y"){
            system("clear");
            mainMenu();
            break;
          }
            
          else{
            return 0;
          }       
        } // end of enemyHealth if statement
        else if(mageHealth<=0){
          cout<<"You have been defeated by the enemy!"<<endl;
          cout<<"Do you wish to go back to Main Menu? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y"){
            system("clear");
            mainMenu();
            break;
          }
            
          else{
            return 0;
          }       
        }
        
        goto Start;       
  
  case '2': //Blink
        
  break;
  
  case '3'://DeepFreeze
        
  break;
  
  default:
           system("clear");
           goto Start;
    }
}
