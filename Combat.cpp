#include <iostream>
#include <string>
#include <unistd.h>
#include "EnemyClass.cpp"
#include "MergedClasses.cpp"
#include "SQLCombat.cpp"
#include "CombatEnding.cpp"
#include "Finish.cpp"
#include <random>

using namespace std;
int storyScore = 0;

int randomNumber(){                       
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1,100); // random numbers between 1-100
    return dis(gen);
}

int enemyDefeated(){
          storyScore +=20;
          cout<<"You have successfully killed your enemy!\n"<<endl;
          Game:
          cout<<"Do you wish to see the ending of the game? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y")
          {
            system("clear");
            combatEnding();
          }
          else if (choice2 == "n" || choice2 == "N")
          {
             cout << "\nThis will close the game." << endl; 
             cout << "Are you sure that you would want to do this? (Y/N)" <<endl;
             string choice3;
             cin >> choice3;
             if (choice3 == "Y" || choice3 == "y")
             {
                 system("clear");
                 cout << "You have exited the game!" << endl;
                 exit(0);
             }
             else if (choice3 == "N" || choice3 == "n")
                 system("clear");
                 goto Game;
         }
          else{
              system("clear");
              goto Game;
          } 
};
 int mageDefeated(){
          storyScore -= 15;
          cout<<"You have been defeated by the enemy!\n"<<endl;
          game:
          cout<<"Do you wish to see the ending of the game? (Y/N): ";
          string choice2;
          cin>>choice2;
          if (choice2 == "y" || choice2 == "Y"){
            system("clear");
            combatEnding();
            }
         else if (choice2 == "n" || choice2 == "N")
         {
             cout << "\nThis will close the game." << endl; 
             cout << "Are you sure that you would want to do this? (Y/N)" <<endl;
             string choice3;
             cin >> choice3;
             if (choice3 == "Y" || choice3 == "y")
             {
                 system("clear");
                 cout << "You have exited the game!" << endl;
                 exit(0);
             }
             else if (choice3 == "N" || choice3 == "n")
             {
                 system("clear");
                 goto game;
             }
             else{
                system("clear");
                goto game;
             }
          } 
}
  
int main(){
 Mage mageObj(1200,500,150,1500,"Staff");
 Enemy enemyObj(2000,400,500,"Axe"); 
 int randomN; // for randomNumber function
  
 //getting values from Mage object
 int mageHealth = mageObj.getHealth();
 int mageMana = mageObj.getMana();
 int mageAttack = mageObj.getAttack();
 int mageDeffence = mageObj.getDefence();
 string mageEquip = mageObj.getEquip();
 //getting values from Enemy object
 int enemyHealth = enemyObj.getEnemyHealth();
 int enemyAttack = enemyObj.getEnemyAttack();
 int enemyDefence = enemyObj.getEnemyDefence();
 string enemyEquip = enemyObj.getEnemyWeapon();
 
 int reduceMageDamage = mageDeffence*0.15;
 int reduceEnemyDamage=enemyDefence*0.4;
 int staffDamage = mageAttack*0.15;
  
 //will be used to prevent using reflect more than twice by the enemy
 int reflectCounter = 0; 
 //will be used to measure distance between enemy and the player
 int enemyDistance = 0; 
 // if Mage's health is below 20%, enemy automatically uses execution on him.
 int mageExecution = mageHealth*0.2;
 //damage of Frostbolt
 int FrostboltDmg = mageAttack - reduceEnemyDamage; 
 //will be used to prevent using DeepFreeze twice a row
 int deepFreezeCounter = 2;
  
 auto spellReflection = [&]()
 {
   cout<<"Enemy reflected your spell. \nYou suffered "<<
          FrostboltDmg<<" damage\n"<<endl;
   mageHealth-= FrostboltDmg;
   mageMana-=250;
   reflectCounter++;
 };
  
 auto outOfMana = [&]()
 {
   cout<<"You have not enough mana for this spell."<<endl;
   if (enemyDistance>=2)
   {
     cout<<"Unfortunately, the enemy was too close, therefore he dealt "<<
       (enemyAttack-reduceMageDamage)<< " damage and you hit him with "<<
       mageObj.getEquip()<< " for "<< mageAttack*0.15<<" damage."<<endl;
     cout<<"You regenerated 400 mana."<<endl;
     mageMana +=400;
     enemyHealth -= mageAttack*0.15;
     mageHealth -= enemyAttack-reduceMageDamage;
   }
   else{
     cout<<"Fortunately, the enemy was too far."<<endl;
     cout<<"You regenerated 400 mana."<<endl;
     enemyDistance++;
     mageMana+=400;
   }
 };
  
  
auto enemyRange = [=,&mageHealth]()
{
  cout<<"Enemy is too close to you, he swung his weapon and dealt "<< 
        (enemyAttack-reduceMageDamage)<< " damage."<<endl;
  mageHealth -= enemyAttack-reduceMageDamage;
};
  
  
auto enemyCharge = [&]()
{
  cout<<"Enemy immediately charged on to you. You suffered "<<
      enemyAttack-reduceMageDamage<<" damage\n"<<endl;
  mageHealth -= enemyAttack-reduceMageDamage;
  enemyDistance++;
  deepFreezeCounter++;
};
  
auto mageExecuted = [&mageHealth]()
{
       cout<<"Your health was too low, enemy has executed you."<<endl;
       mageHealth=0;
       storyScore -=15;
};
  
auto castDeepFreeze = [&]()
{
           cout<< "The enemy is stunned and you instantly casted Frostbolt"<<
              " which dealt "<< FrostboltDmg<< " damage.\n"<<endl;
           deepFreezeCounter++;
           enemyHealth -=FrostboltDmg;
           enemyDistance =0;
           mageMana -= 300;
};
  
auto castBlink = [&mageMana]()
{
   cout<< "You blinked away from the enemy but the fight's not over yet!\n"<<endl;
   mageMana-=180;
};
  
auto castLuckyBlink = [=,&enemyHealth, &mageMana]()
{
  cout<< "You blinked away from the enemy and luckily casted an instant frostbolt. \n\nDamage dealt to enemy: "<<FrostboltDmg<< "\n\nNonetheless, act quickly"<<"'cause he is getting closer!\n"<<endl;
  enemyHealth -= FrostboltDmg;
  mageMana-=180;
};
  
auto castFrostbolt = [FrostboltDmg, &enemyHealth, &mageMana]()
{
  cout<< "Frosbolt dealt "<< FrostboltDmg<< " damage.\n"<<endl;
  enemyHealth-=FrostboltDmg;
  mageMana-=250;
};
  
 cout << endl;
  
 cout<< "You start to Run towards the source of the sound that you are hearing in some hope for some answers" << endl;
    sleep(3);
 cout << "Your near the source of where the sound is coming from, you start to notice that the person you see looks a bit odd.\n" << endl;
    sleep(3);
 cout << "They look like they have some presence around them, and an ominous aura coming off of them as well.\n" << endl;
    sleep(3);
 cout << "They seem to have noticed you, you try to flee but they may instantly attack the moment you turn your back\n" << endl;
    sleep(3);
 cout << "Your Forced into a fight, with no other choice.\n\n" << endl;
    sleep(3);
 cout<< "---------------You've entered battle---------------\n"<<endl;
 cout<< "YOUR STATS AND SPELLS: "<<endl;
 mageObj.toString();
 cout<< "\n- Frostbolt  \n- Blink \n- Deep Freeze"<<endl;
  sleep(2);
 cout<< "\nENEMY'S STATS AND ABILITIES: "<<endl;
 enemyObj.toEnemyString();
    cout << endl;
 enemyObj.abilities();
    cout << endl;
 sleep(2);
 cout << "The distance between you and your enemy is just a few meters. "<<endl;
 cout<< "Remember only one of you will walk out of this alive.\n"<<endl;
    sleep(3);
    
  
 cout<<"-------------------LET THE BATTLE BEGIN!!!-------------------\n"<<endl;
  Start: // start of each combat round
  mageObj.spells();
  
  cout<< "\nYour health: "<<mageHealth<< "\nMana: "<< mageMana<<endl;
  cout<< "Enemy's health: "<<enemyHealth<<endl;
  cout<<"\nChoice: ";
  char choice;
  randomN = randomNumber();
  cin>>choice;
  cout << endl;
  
  
switch (choice){
  case '1':  //Frostbolt     
       enemyDistance++;
       deepFreezeCounter=2;
        
     if (mageMana<250)
       {
         outOfMana();
       }
     else{
               
         if(enemyDistance<2){
            cout<<"Enemy's getting closer, you should use blink to get further away from him!\n"<<endl;
          }
         else if(enemyDistance>=2){
                enemyRange(); 
             if (mageHealth<mageExecution){
                 mageExecuted();           
              }
         }
             
         if (randomN>60 && reflectCounter<=1 ){   
             spellReflection();
         }
         else{
             castFrostbolt();
         }      
     }
        
      if(enemyHealth<=0){
           enemyHealth = 0;
           insertToCombat(mageHealth, mageMana, enemyHealth);
           enemyDefeated();
         
       } 
       else if(mageHealth<=0){
          mageHealth = 0;
          insertToCombat(mageHealth, mageMana, enemyHealth);
           mageDefeated();
       }
      
         goto Start;       
  
  case '2': //Blink 
        enemyDistance=0;
        deepFreezeCounter=2;
         
        if (mageMana<180)
       {
         outOfMana();
       }
        
        else{
           if (randomN>70){
              enemyCharge();
              mageMana-=180;
               if (mageHealth<mageExecution){
                  mageExecuted();         
               }    
         }
        
            else if (randomN>30){
              castLuckyBlink();
            }
            else{
              castBlink();
            }
        }
        
        
      if(enemyHealth<=0){
           enemyHealth = 0;
           insertToCombat(mageHealth, mageMana, enemyHealth);
           enemyDefeated();
         
        } 
       else if(mageHealth<=0){
          mageHealth = 0;
          insertToCombat(mageHealth, mageMana, enemyHealth);
           mageDefeated();
        }
       goto Start;
        
  
  case '3'://DeepFreeze
        if (mageMana<300)
       {
         outOfMana();
         deepFreezeCounter=2;
       }
        
        else{
            if (deepFreezeCounter%2 == 0){          
                castDeepFreeze();
             }
 
            else{
                cout<< "You cannot use DeepFreeze this round!\n"<<endl;
                enemyCharge();
              if (mageHealth<mageExecution){
                  mageExecuted();       
               }
            }
         }
         
        
        if(enemyHealth<=0){
           enemyHealth = 0;
           insertToCombat(mageHealth, mageMana, enemyHealth);
           enemyDefeated();
         
        } 
        else if(mageHealth<=0){
          mageHealth = 0;
          insertToCombat(mageHealth, mageMana, enemyHealth);
           mageDefeated();
        }      
  goto Start;
   
        
  default:
           system("clear");
           goto Start;
 }
    
  return 0;
}
