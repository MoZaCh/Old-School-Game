#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Prints the leaderboard 
void leaderboardResults()
{
    try //try statement do this unless error occurs 
    {
        sqlite::sqlite db( "testdb.db" ); //Opens the connection
        auto cur = db.get_statement(); //Creates a cursor on this connection
        
        cur->set_sql("SELECT *"
                     "FROM users "
                     "ORDER BY score ASC;"); //SQL command
        cur->prepare(); //Sends to database
        int i =1;
  
        while(cur->step())//Getting results
        {
            if (cur->get_int(3) == 0) //Checking if condition meets
            {
                continue;
            }
            else
            {
                cout << i << " |Username: " <<  cur->get_text(1) << " |Score: " << cur->get_int(3) <<endl; //Printing leaderboard results
                i++;
            }
        } 
    }
    catch (sqlite::exception e) //Catching the sqlerror to avoid the program to crash
    {
        cerr << e.what() << endl;
        return;
    }
    return;
}

//Updata score in DB
int updateScoreSQL(int global)
{
  try
  {  
    sqlite::sqlite db("testdb.db"); //Opens the connection
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("UPDATE users SET score = (?) "
                 "WHERE id = ?;"); //SQL command
    cur->prepare(); //Sends to database
    cur->bind(1, global); //binding the global variable to the first '?'
    cur->bind(2, userID); //binding the userID variable to the secind '?'
    cur->step();
  }
  catch (sqlite::exception e) //Catching SQL exception 
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}

//Main room function
void mainRoom()
{
  cout << "**Hallway**" << endl;
  cout<<"You are standing in the centre, to the right is the living room and to the left is the front room."<<endl;
  cout<<"The stairs is slightly ahead of you and the room opposite you is the dining room."<<endl;
  sleep(1); //Displays the following message after a second or so
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
}

//Upstairs function
void upstairsHallway()
{
  cout << "***Upstairs Hallway***" << endl;
  cout<<"You are now on the first floor. There is only 1 room ahead of you which is the bedroom or you can go back downstairs." << endl;
  sleep(1); //Displays the following message after a second or so
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
}

//Key found function to present score and end game
void keyfound()
{
  cout <<"***Objective Complete***" << endl;
  cout << "Well done! You have found the missing key and have now freed yourself!!" << endl;
  cout << "That took you " << global << " moves!" << endl;
  cout << endl;
  cout << "***Leaderboard***" << endl;
  leaderboardResults();
  sleep(5); //Displays the following message after 5 seconds
  exit(0); //exits the whole program
}

//frontroom function
int frontRoom()
{
    string frontroomMove;
    bool leaveRoom = false;
    cout << "**Front room**" << endl;
    cout<<"You have now entered the front room there is a fireplace, a sofa, an oak table, a small TV and a coat stand" << endl;
    sleep(1); //Displays the following message after a second or so
    cout << endl;
    cout<<"Please enter your next move..."<<endl;
    
        
    while (leaveRoom==false)  //While loop - keeps looping till a certain condition is met
    {
        if (getline(cin,frontroomMove)) //stores the input into the variable 
           {transform(frontroomMove.begin(), frontroomMove.end(), frontroomMove.begin(), ptr_fun<int, int>(toupper));
    }
    if (frontroomMove.find("SOFA") != string::npos) //Checks for keywords in the string variable 
        {
        cout<<"The key is not on the sofa"<< endl;
        global ++; //Adds 1 to the move counter
        }
    else if (frontroomMove.find("BEHIND THE TV") != string::npos || frontroomMove.find("TV") != string::npos) //Checks for keywords in the string variable  
        {
        cout<<"The key is not near the TV"<< endl;
        global ++; //Adds 1 to the move counter
        }  
    else if (frontroomMove.find("FIREPLACE")!=string::npos) //Checks for keywords in the string variable  
        {
        cout<<"The key is not on the fireplace"<< endl;
        global ++; //Adds 1 to the move counter
        }
    else if (frontroomMove.find("ON THE TABLE")!=string::npos) //Checks for keywords in the string variable  
        {
        cout<<"The key is not on the oak table"<< endl;
        global ++; //Adds 1 to the move counter
        }  
    else if (frontroomMove.find("COAT STAND")!=string::npos || frontroomMove.find("COATSTAND")!=string::npos) //Checks for keywords in the string variable 
        {
        cout<<"The key is not near the coat stand"<< endl;
        global ++; //Adds 1 to the move counter
        }  
    else if (frontroomMove.find("LEAVE") != string::npos|| frontroomMove.find("EXIT")!=string::npos) //Checks for keywords in the string variable 
        {
        cout<<"You have now left the front room"<< endl;
        global ++; //Adds 1 to the move counter
        system("clear");
        mainRoom(); //Clears the terminal before calling the next function
        break;
        return 0;
        }    
    else 
    {
        cout << endl;
        cout << "Sorry that isn't an option!" << endl;
        cout << endl;
        cout << "**Front room options available**" << endl;
        cout << "-on the sofa \n-behind the TV\n-on the fireplace \n-on the table \n-leave" << endl;
        cout << endl;
        cout << "Please enter your next move..." << endl;
    }
    
    }
    
  return 0;
}

//Livingroom function 
int livingRoom()
{ 
  string livingroomMove;
  bool leaveRoom = false;
  cout << "**Living room**" << endl;
  cout<< "You have now entered the living room there is a leather sofa, a dusty table and a huge window" << endl;
  sleep(1); //Displays the following message after a second or so
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
  
  while (leaveRoom == false) //While loop - keeps looping till a certain condition is met
  {
    if (getline(cin, livingroomMove)) //stores the input into the variable 
      {transform(livingroomMove.begin(), livingroomMove.end(), livingroomMove.begin(), ptr_fun<int, int>(toupper));
      }
    
    if (livingroomMove.find("ON THE SOFA") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not on the leather sofa" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (livingroomMove.find("UNDER THE SOFA") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not under the sofa" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (livingroomMove.find("TABLE") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not on the table" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (livingroomMove.find("UNDER THE TABLE") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not under the table" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (livingroomMove.find("WINDOW") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not near the window" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (livingroomMove.find("LEAVE") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "You have now left the living room" << endl;
      global ++; //Adds 1 to the move counter
      system("clear"); //Clears the terminal before calling the next function
      mainRoom();
      break;
      return 0;
    }
    else 
    {
        cout << endl;
        cout << "Sorry that isn't an option!" << endl;
        cout << endl;
        cout << "**Living room options available**" << endl;
        cout << "-on the sofa \n-under the sofa \n-on the table \n-under the table \n-on the window \n-leave" << endl;
        cout << endl;
        cout << "Please enter your next move..." << endl;
    }
  }
}
        
//Dining room function
int diningRoom()
{
    string diningMove;
    bool leaveRoom = false;
    cout << "**Dining Room**" << endl;
    cout<<"You have now entered the dining room. There are chairs surrounding a vintage table."<<endl;
    cout<<"There is a dusty bookshelf on the right-hand side along with an old dish washer. "<<endl;
    sleep(1);
    cout << endl;
    cout<<"Please enter your next move..."<<endl;
    
  while (leaveRoom==false)  //While loop - keeps looping till a certain condition is met
  {
    if (getline(cin, diningMove)) //stores the input into the variable 
    {transform(diningMove.begin(), diningMove.end(), diningMove.begin(), ptr_fun<int, int>(toupper));
    }
            
    if (diningMove.find("ON THE TABLE") != string::npos) //Checks for keywords in the string variable  
    {
      cout << "The key is not on the table" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("ON THE CHAIRS") != string::npos|| diningMove.find("ON THE CHAIR")!=string::npos) //Checks for keywords in the string variable 
    { 
      cout << "The key is not on the chair(s)" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("UNDER THE TABLE") != string::npos) //Checks for keywords in the string variable  
    {
      cout << "The key is not under the table" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("IN THE BOOKSHELF") != string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not in the bookshelf" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("ON THE DISH WASHER") != string::npos || diningMove.find("ON THE DISHWASHER") != string::npos) //Checks for keywords in the string variable  
    {
      cout << "The key is not inside the dish washer" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("INSIDE THE DISHWASHER") != string::npos || diningMove.find("INSIDE THE DISH WASHER")!=string::npos) //Checks for keywords in the string variable 
    { 
      cout << "The key is not on the dish washer" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if (diningMove.find("LEAVE") != string::npos|| diningMove.find("EXIT")!=string::npos) //Checks for keywords in the string variable  
    {
      cout << "You have now left the dining room" << endl;
      global ++; //Adds 1 to the move counter
      system("clear"); //Clears the terminal before calling the next function
      mainRoom(); //Calls the mainroom function
      break;
      return 0;     
    }
    else 
    {
        cout << endl;
        cout << "Sorry that isn't an option!" << endl;
        cout << endl;
        cout << "**Dining room options available**" << endl;
        cout << "-on the table \n-on the chairs \n-under the table \n-under the table \n-in the bookshelf \n-inside the dish washer \n-on the dish washer \n-leave" << endl;
        cout << endl;
        cout << "Please enter your next move..." << endl;
    }
  }
}

//Bedroom function 
int bedRoom()
{
  string bedroomMove;
  bool leaveroom = false;
  cout << "**Bedroom**" << endl;
  cout << "You are now in the bedroom. There is a bed, massive wardrobe and a vintage oak trunk."<<'\n';
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
  
  
  while (leaveroom==false)  //While loop - keeps looping till a certain condition is met
  {
     if (getline(cin,bedroomMove)) //stores the input into the variable 
           {transform(bedroomMove.begin(), bedroomMove.end(), bedroomMove.begin(), ptr_fun<int, int>(toupper));
    }
    
    if (bedroomMove.find("ON THE BED")!= string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not on the bed" << endl;
      global ++; //Adds 1 to the move counter
    }
    else if(bedroomMove.find("UNDER THE BED")!=string::npos) //Checks for keywords in the string variable 
    {
      cout << "The key is not under the bed" << endl;
      global ++; //Adds 1 to the move counter
    }
    
    else if(bedroomMove.find("IN THE TRUNK")!=string::npos) //Checks for keywords in the string variable 
    {
      system("clear"); //Clears the terminal before calling the next function
      updateScoreSQL(global); //Calls the updatescore function to update the score
      keyfound(); //Calls the keyfound function
      return 0;
      break;
    }
    
     else if (bedroomMove.find("ON THE TRUNK")!=string::npos) //Checks for keywords in the string variable 
     {
       cout << "The key is not on the trunk" << endl;
       global ++; //Adds 1 to the move counter
     }
     else if (bedroomMove.find("LEAVE")!=string::npos || bedroomMove.find("EXIT")!=string::npos) //Checks for keywords in the string variable 
     {
       cout << "You have now left the first bedroom" << endl;
       global ++; //Adds 1 to the move counter
       system("clear"); //Clears the terminal before calling the next function
       upstairsHallway();
       return 0;
     }
     else
     {
        cout << endl;
        cout << "Sorry that isn't an option!" << endl;
        cout << endl;
        cout << "**Bedroom options available**" << endl;
        cout << "-on the bed \n-under the bed \n-on the trunk \n-in the trunk \n-leave" << endl;
        cout << endl;
        cout << "Please enter your next move..." << endl;
     }
  }
}

//Upstairs function
int upstairs()
{
  string firstfloorMove;
  bool leaveRoom = false;
  upstairsHallway();

  
  while (leaveRoom==false)  //While loop - keeps looping till a certain condition is met
  {
    if (getline(cin,firstfloorMove)) //stores the input into the variable 
           {transform(firstfloorMove.begin(), firstfloorMove.end(), firstfloorMove.begin(), ptr_fun<int, int>(toupper));
    }
    if (firstfloorMove.find("BEDROOM") != string::npos) //Checks for keywords in the string variable 
    {
      global ++; //Adds 1 to the move counter
      system("clear"); //Clears the terminal before calling the next function
      bedRoom(); //Calls the bedroom function
    }
    else if (firstfloorMove.find("LEAVE") != string::npos|| firstfloorMove.find("EXIT")!=string::npos || firstfloorMove.find("DOWNSTAIRS")!=string::npos) //Checks for keywords in the string variable 
    {
      cout << "You are now back downstairs" << endl;
      global ++; //Adds 1 to the move counter
      system("clear"); //Clears the terminal before calling the next function
      mainRoom(); //Calls the main room function
      return 0; //returns 0, ends the function
    }
    else
    {
        cout << endl;
        cout << "Sorry that isn't an option!" << endl;
        cout << endl;
        cout << "**First floor options available**" << endl;
        cout << "-bedroom \n-leave" << endl;
        cout << endl;
        cout << "Please enter your next move..." << endl;
    }
  }
}
