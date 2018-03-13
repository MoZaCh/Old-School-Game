#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "common.h"
#include "allRooms.cpp"
using namespace std;

bool ifKeyFound = false;

bool key;


int mainGame(int userId)
{  
    userID = userId; //importing username id from the database -sqlcon page
    string firstMove;
    bool ifKeyFound = false;
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
    sleep(2);
    cout<<"You are required to hunt through the rooms for the key..."<<endl;
    sleep(3);
    cout<<"You are standing in the centre, to the right is the living room and to the left is the front room."<<endl;
    sleep(3);
    cout<<"The stairs is slightly ahead of you and the room opposite you is the dining room."<<endl;
    sleep(1);
    cout << endl;
    
  
    while (ifKeyFound == false)
    {
      if (getline (cin, firstMove))
      {
        transform(firstMove.begin(), firstMove.end(), firstMove.begin(), ptr_fun<int, int>(toupper));   
      }
        if (firstMove.find("FRONT ROOM") != string::npos)  
        {
          global ++;
          system("clear");
          frontRoom();
        }
        
        else if (firstMove.find("LIVING ROOM") != string::npos)//;
        {
          global ++;
          system("clear");
          livingRoom();    
        }
        
        else if (firstMove.find("DINING ROOM")!=string::npos)
        {
           global ++;
           system("clear");
           diningRoom();
        }
        
        else if( firstMove.find("GO TO THE STAIRS")!=string::npos)
        {
           global ++;
           system("clear");
           cout<<"You are now bottom of the stairs facing up"<<endl;
        }
        
        else if (firstMove.find("UPSTAIRS")!=string::npos)
        {
            global ++;
            system("clear");
            upstairs();
        }
        else if (firstMove.find("END GAME")!=string::npos)
        {
            system("clear");
            exit(0);
        }
        else if (begin == 1)
        {
            cout << "Please enter your first move..." << endl;
            begin ++;
        }
        else 
        {
            cout << "Sorry i didn't get that!" << endl;         
        }
      
    }
    
    return 0;
}
