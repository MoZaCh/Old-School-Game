#include <iostream>
#include <string>
#include <unistd.h>
#include "EnemyClass.cpp"
#include "MergedClasses.cpp"
#include <random>


using namespace std;

int randomNumber(){                       
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1,100); // random numbers between 1-100
    return dis(gen);
}
int mageDefeated(){
          game:
          cout<<"You have been defeated by the enemy!\n"<<endl;
          cout<<"Do you wish to go back to (some stage of the game)? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y"){
            system("clear");
            cout<<"here will be function to jump somewhere in the game"<<endl;
            }
         else if (choice2 == "n" || choice2 == "N")
         {
             cout << "\nThis will close the game." << endl; 
             cout << "Are you sure that you would want to do this? (Y/N)" << endl;
             string choice3;
             cin >> choice3;
             if (choice3 == "Y" || choice3 == "y")
             {
                 system("clear");
                 cout << "You have exited the game!" << endl;
                 return 0;
             }
             else if (choice3 == "N" || choice3 == "n")
                 system("clear");
                 goto game;
         }
           else{
            system("clear");
               goto game;
          } 
}
int enemyDefeated(){
          Game:
          cout<<"You have successfully killed your enemy!\n"<<endl;
          cout<<"Do you wish to go back to (some stage of the game)? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y")
          {
            system("clear");
            cout<<"here will be function to jump somewhere in the game"<<endl;
          }
          else if (choice2 == "n" || choice2 == "N")
          {
             cout << "\nThis will close the game." << endl; 
             cout << "Are you sure that you would want to do this? (Y/N)" << endl;
             string choice3;
             cin >> choice3;
             if (choice3 == "Y" || choice3 == "y")
             {
                 system("clear");
                 cout << "You have exited the game!" << endl;
                 return 0;
             }
             else if (choice3 == "N" || choice3 == "n")
                 system("clear");
                 goto Game;
         }
          else{
              system("clear");
              goto Game;
          } 
}

void mageExecuted(){
          cout<<"Your health was too low, enemy has executed you."<<endl;
}
  
int main(){
 Mage mageObj(1200,500,150,1500,"Staff");
  Enemy enemyObj(2000,400,500,"Axe");
  
 cout<< "---------------You've entered battle---------------\n"<<endl;
 cout<< "YOUR STATS AND SPELLS: "<<endl;
 mageObj.toString();
 cout<< "\n- Frostbolt  \n- Blink \n- Deep Freeze"<<endl;
  
 cout<< "\nENEMY'S STATS AND ABILITIES: "<<endl;
 enemyObj.toEnemyString();
    cout << endl;
 enemyObj.abilities();
    cout << endl;
  
  
 //getting values from Mage object
 int mageHealth = mageObj.getHealth();
 int mageMana = mageObj.getMana();
 int mageAttack = mageObj.getAttack();
 int mageDeffence = mageObj.getDefence();
 //getting values from Enemy object
 int enemyHealth = enemyObj.getEnemyHealth();
 int enemyAttack = enemyObj.getEnemyAttack();
 int enemyDefence = enemyObj.getEnemyDefence();
 
 int reduceMageDamage = mageDeffence*0.15;
 int reduceEnemyDamage=enemyDefence*0.4;
  
 //will be used to prevent using reflect more than twice by the enemy
 int reflectCounter = 0; 
 //will be used to measure distance between enemy and the player
 int enemyDistance = 0; 
 // if Mage's health is below 20%, enemy automatically uses execution on him.
 int mageExecution = mageHealth*0.2;
 //damage of Frostbolt
 int FrostboltDmg = mageAttack - reduceEnemyDamage; 
 //will be used to prevent using DeepFreeze twice a row
 int deepFreezeCounter = 0;
 
  
 cout<< "You are standing in the arena. The distance between you and your \nenemy is just a few meters. "<<endl;
 cout<< "Remember only one of you will walk out of this alive.\n"<<endl;
 cout<<"-------------------LET THE BATTLE BEGIN!!!-------------------\n"<<endl;
  
  
  Start:
  int randomN;
  mageObj.spells();
  cout<< "Your health: "<<mageHealth<< "\nMana: "<< mageMana<<endl;
  cout<< "\nEnemy's health: "<<enemyHealth<<endl;
  cout<<"\nChoice: ";
  char choice;
  randomN = randomNumber();
  cin>>choice;
    cout << endl;
  
  
    switch (choice){
    
  case '1': //Frostbolt     
       mageMana-=250;
       enemyDistance++;
       deepFreezeCounter=0;
        
       if(enemyDistance<2){
          cout<<"Enemy's getting closer, you should use blink to get further away from him!\n"<<endl;
        }
        
       else if(enemyDistance>=2){
         cout<<"Enemy is too close to you, he swung his weapon and dealt "<< 
           (enemyAttack-reduceMageDamage)<< " damage.\n"<<endl;
         mageHealth -= enemyAttack-reduceMageDamage;
         if (mageHealth<mageExecution){
          mageExecuted();
          mageHealth=0;
        }
       }
             
       if (randomN>60 && reflectCounter<=1){
         mageHealth-= FrostboltDmg;
         cout<<"Enemy reflected your spell. \nYou suffered "<<
                             FrostboltDmg<<" damage\n"<<endl;
         reflectCounter++;
       }
       else{
         cout<< "Frosbolt dealt "<< FrostboltDmg<< " damage.\n"<<endl;
         enemyHealth-=FrostboltDmg;
       }      
        
       if(enemyHealth<=0){
         enemyDefeated();
         break;
        }
        
        else if(mageHealth<=0){
         mageDefeated();
          break;
        }
        
        goto Start;       
  
  case '2': //Blink
        enemyDistance=0;
        deepFreezeCounter=0;
        cout<<enemyDistance<<endl;
        mageMana-=180;
         if (randomN>70){
          mageHealth -= enemyAttack-reduceMageDamage;
          cout<<"Enemy immediately charged on to you. You suffered "<<
                             enemyAttack-reduceMageDamage<<" damage\n"<<endl;
           if (mageHealth<mageExecution){
          mageExecuted();
          mageHealth=0;
        }
          
         }
        else if (randomN>30){
          cout<< "You blinked away from the enemy and luckily casted an instant frostbolt. \n\nDamage dealt to enemy: "<<FrostboltDmg<< "\n\nNonetheless, act quickly"<< 
            "'cause he is getting closer!\n"<<endl;
          enemyHealth -= FrostboltDmg;
        }
        else{
          cout<< "You blinked away from the enemy but the fight's not over yet!\n"<<endl;
        }
        
         if(enemyHealth<=0){
         enemyDefeated();
         break;
        }
        
        else if(mageHealth<=0){
         mageDefeated();
          break;
        
        }
        
  goto Start;
  
  case '3'://DeepFreeze
        if (deepFreezeCounter%2 == 0){
           mageMana -= 300;
           enemyDistance = 0;
           deepFreezeCounter++;
           cout<< "--------counter: "<<deepFreezeCounter<<endl;
           cout<< "The enemy is stunned and you instantly casted Frostbolt"<<
              " which dealt "<< FrostboltDmg<< " damage.\n"<<endl;
          enemyHealth -=FrostboltDmg;
        }
   
         else{
              mageHealth -= enemyAttack-reduceMageDamage;
              cout<< "You cannot use DeepFreeze this round!\n"<<endl;
              cout<<"Enemy immediately charged on to you. You suffered "<<
                   enemyAttack-reduceMageDamage<<" damage\n"<<endl;
              if (mageHealth<mageExecution){
                mageExecuted();
                mageHealth=0;
            }
          }
         
         if(enemyHealth<=0){
          enemyDefeated();  
           break;
        }
        
        else if(mageHealth<=0){
          mageDefeated();
          break;
        }
              
  goto Start;
  
  default:
           system("clear");
           goto Start;
    }
  return 0;
}

