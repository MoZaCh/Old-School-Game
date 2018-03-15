#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "common.h"
#include "allRooms.cpp"
using namespace std;

/*Coded by Mohammed Zahed Choudhury START*/

bool ifKeyFound = false; //Key is not found 'false'


int mainGame(int userId)
{  
    userID = userId; //importing username id from the database -sqlcon page
    string firstMove;//first move string variable declared
    int begin = 1;
    
    cout << "***Instructions***" << endl;
    cout << endl;
    cout <<"Type 'End game' to exit the game" << endl;
    cout <<"Type 'Leave' or 'exit' to leave a room" << endl;
    cout << endl;
    cout << "You will be given a description of objects surrounding you - example: a massive TV, table." << endl;
    cout << "Example moves: 'on the table' - 'under the table' - 'behind the tv' etc" << endl;
    cout << endl;
    cout << "***Objective***" << endl;
    cout << endl;
    cout<<"You are locked inside an ancient house and in order to escape you need to find the missing key."<<endl;
    sleep(2); //slowly prints the following message after 2 seconds
    cout<<"You are required to hunt through the rooms for the key..."<<endl;
    sleep(3); //slowly prints the following message after 3 seconds
    cout<<"You are standing in the centre, to the right is the living room and to the left is the front room."<<endl;
    sleep(3); //slowly prints the following message after 2 seconds
    cout<<"The stairs is slightly ahead of you and the room opposite you is the dining room."<<endl;
    sleep(1);
    cout << endl;
    
  
    while (ifKeyFound == false)  //While loop - keeps looping till a certain condition is met
    {
      if (getline (cin, firstMove)) //stores the input into the variable 
      {
        transform(firstMove.begin(), firstMove.end(), firstMove.begin(), ptr_fun<int, int>(toupper));   
      }
        if (firstMove.find("FRONT ROOM") != string::npos || firstMove.find("FRONTROOM") != string::npos)  //Checks for keywords in the string variable  
        {
          global ++; //Adds 1 to the move counter
          system("clear"); //Clears the terminal before calling the next function
          frontRoom();
        }
        
        else if (firstMove.find("LIVING ROOM") != string::npos || firstMove.find("LIVINGROOM") != string::npos) //Checks for keywords in the string variable 
        {
          global ++; //Adds 1 to the move counter
          system("clear"); //Clears the terminal before calling the next function
          livingRoom();    
        }
        
        else if (firstMove.find("DINING ROOM")!=string::npos || firstMove.find("DININGROOM") != string::npos) //Checks for keywords in the string variable 
        {
           global ++; //Adds 1 to the move counter
           system("clear"); //Clears the terminal before calling the next function
           diningRoom();
        }
        
        else if( firstMove.find("GO TO THE STAIRS")!=string::npos) //Checks for keywords in the string variable 
        {
           global ++; //Adds 1 to the move counter
           system("clear"); //Clears the terminal before calling the next function
           cout<<"You are now bottom of the stairs facing up"<<endl;
        }
        
        else if (firstMove.find("UPSTAIRS")!=string::npos) //Checks for keywords in the string variable 
        {
            global ++; //Adds 1 to the move counter
            system("clear"); //Clears the terminal before calling the next function
            upstairs();
        }
        else if (firstMove.find("END GAME")!=string::npos) //Checks for keywords in the string variable 
        {
            system("clear"); //Clears the terminal before exiting the game
            exit(0); //Exits the game 
        }
        else if (begin == 1)
        {
            cout << "Please enter your first move..." << endl;
            begin ++;
        }
        else 
        {
            cout << endl;
            cout << "Sorry that isn't an option!" << endl;
            cout << endl;
            cout << "**Options available**" << endl;
            cout << "-living room \n-front room \n-dining room \n-go to the stairs \n-upstairs \n-end game" << endl;
            cout << endl;
            cout << "Please enter your next move..." << endl;
        }
      
    }
    
    return 0;
}

/*Coded by Mohammed Zahed Choudhury END*/
