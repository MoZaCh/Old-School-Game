#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>
#include "Finish.cpp"
#pragma once
using namespace std;

int combatEnding(){
	  
	  cout << "You Manage to Defeat the enemy and see the aura that was shrouding them disappear and fly away in the distance." << endl;
   sleep(2);
    cout << "You decide to search the persons body for anything \nYou find a not on the body. It seems to be some type of coordinate." << endl;
    sleep(2);
    cout << "Maybe this can can be some type of clue, but you have nothing else to go on." << endl;
    sleep(2);
    cout << "You can only hope this location would be the place youll be able to find the answers you need..." << endl;
    sleep(3);
 string choice;
  
 cout<< "Would you like to see the credits for this game(Y/N)?: ";
 cin>>choice;
  
 if (choice == "y" || choice == "Y"){ 
     finish();
 }
  else{
    exit(0);
  }
    
	
    return 0;
  }
