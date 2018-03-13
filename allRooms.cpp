#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Prints the leaderboard 
void leaderboardResults()
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("SELECT *"
               "FROM users "
               "ORDER BY score ASC;"); //SQL command
  cur->prepare(); //Sends to database
  int i =1;
  
  while(cur->step())
  {
    if (cur->get_int(3) == 0)
    {
      continue;
    }
    else
    {
      cout << i << " |Username: " <<  cur->get_text(1) << " |Score: " << cur->get_int(3) <<endl;
      i++;
    }
  }
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
    cur->bind(1, global);
    cur->bind(2, userID);
    cur->step();
  }
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}


void mainRoom()
{
  cout << "**Hallway**" << endl;
  cout<<"You are standing by the door, to your left is the front room and the room slightly ahead and to the left is the living room"<<endl;
  cout<<"The room directly ahead of you is the kitchen while the stairs are to your right"<<endl;
  sleep(1);
  cout << endl;
  cout<<"Please choose your next move..."<<endl;
}

void upstairsHallway()
{
  cout << "***Upstairs Hallway***" << endl;
  cout<<"You are now on the first floor. There is only 1 room ahead of you or you can go back downstairs." << endl;
  sleep(1);
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
}

void keyfound()
{
  cout <<"***Objective Complete***" << endl;
  cout << "Well done! You have found the missing key and have now freed yourself!!" << endl;
  cout << "That took you " << global << " moves!" << endl;
  cout << endl;
  cout << "***Leaderboard***" << endl;
  leaderboardResults();
  sleep(5);
  exit(0);
}


int frontRoom()
{
    string frontroomMove;
    bool leaveRoom = false;
    cout << "**Front room**" << endl;
    cout<<"You have now entered the front room there is a fireplace, a sofa, an oak table and a small TV on a TV stand" << endl;
    sleep(1);
    cout << endl;
    cout<<"Please enter your next move..."<<endl;
    
        
    while (leaveRoom==false)
    {
        if (getline(cin,frontroomMove))
           {transform(frontroomMove.begin(), frontroomMove.end(), frontroomMove.begin(), ptr_fun<int, int>(toupper));
    }
    if (frontroomMove.find("SOFA") != string::npos)  
        {
        cout<<"The key is not on the sofa"<< endl;
        global ++;
        }
    else if (frontroomMove.find("BEHIND THE TV") != string::npos || frontroomMove.find("TV") != string::npos)  
        {
        cout<<"The key is not near the TV"<< endl;
        global ++;
        }  
    else if (frontroomMove.find("FIREPLACE")!=string::npos)  
        {
        cout<<"The key is not on the fireplace"<< endl;
        global ++;
        }
    else if (frontroomMove.find("ON THE TABLE")!=string::npos)  
        {
        cout<<"The key is not on the oak table"<< endl;
        global ++;
        }  
    else if (frontroomMove.find("LEAVE") != string::npos|| frontroomMove.find("EXIT")!=string::npos)  
        {
        cout<<"You have now left the front room"<< endl;
        global ++;
        system("clear");
        mainRoom();
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

int livingRoom()
{ 
  string livingroomMove;
  bool leaveRoom = false;
  cout << "**Living room**" << endl;
  cout<< "You have now entered the living room there is a leather sofa, a dusty table and a huge window" << endl;
  sleep(1);
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
  
  while (leaveRoom == false)
  {
    if (getline(cin, livingroomMove))
      {transform(livingroomMove.begin(), livingroomMove.end(), livingroomMove.begin(), ptr_fun<int, int>(toupper));
      }
    
    if (livingroomMove.find("ON THE SOFA") != string::npos)
    {
      cout << "The key is not on the leather sofa" << endl;
      global ++;
    }
    else if (livingroomMove.find("UNDER THE SOFA") != string::npos)
    {
      cout << "The key is not under the sofa" << endl;
      global ++;
    }
    else if (livingroomMove.find("TABLE") != string::npos)
    {
      cout << "The key is not on the table" << endl;
      global ++;
    }
    else if (livingroomMove.find("UNDER THE TABLE") != string::npos)
    {
      cout << "The key is not under the table" << endl;
      global ++;
    }
    else if (livingroomMove.find("WINDOW") != string::npos)
    {
      cout << "The key is not on the window sill" << endl;
      global ++;
    }
    else if (livingroomMove.find("LEAVE") != string::npos)
    {
      cout << "You have now left the living room" << endl;
      global ++;
      system("clear");
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
    
  while (leaveRoom==false)
  {
    if (getline(cin, diningMove))
    {transform(diningMove.begin(), diningMove.end(), diningMove.begin(), ptr_fun<int, int>(toupper));
    }
            
    if (diningMove.find("ON THE TABLE") != string::npos)  
    {
      cout<<"The key is not on the table"<<'\n';
      global ++;
    }
    else if (diningMove.find("ON THE CHAIRS") != string::npos|| diningMove.find("ON THE CHAIR")!=string::npos)  
    { 
      cout<<"The key is not on the chair(s)"<<'\n';
      global ++;
    }
    else if (diningMove.find("UNDER THE TABLE") != string::npos)  
    {
      cout<<"The key is not under the table."<<'\n';
      global ++;
    }
    else if (diningMove.find("IN THE BOOKSHELF") != string::npos)  
    {
      cout<<"The key is not in the bookshelf"<<'\n';
      global ++;
    }
    else if (diningMove.find("ON THE DISH WASHER") != string::npos || diningMove.find("ON THE DISHWASHER") != string::npos)  
    {
      cout<<"The key is not inside the dish washer"<<'\n';
      global ++;
    }
    else if (diningMove.find("INSIDE THE DISHWASHER") != string::npos || diningMove.find("INSIDE THE DISH WASHER")!=string::npos)  
    { 
      cout<<"The key is not on the dish washer"<<'\n';
      global ++;
    }
    else if (diningMove.find("LEAVE") != string::npos|| diningMove.find("EXIT")!=string::npos)  
    {
      cout<<"You have now left the dining room"<<'\n';
      global ++;
      system("clear");
      mainRoom();
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

int bedRoom()
{
  string bedroomMove;
  bool leaveroom = false;
  cout << "**Bedroom**" << endl;
  cout << "You are now in the bedroom. There is a bed, massive wardrobe and a vintage oak trunk."<<'\n';
  cout << endl;
  cout<<"Please enter your next move..."<<endl;
  
  
  while (leaveroom==false)
  {
     if (getline(cin,bedroomMove))
           {transform(bedroomMove.begin(), bedroomMove.end(), bedroomMove.begin(), ptr_fun<int, int>(toupper));
    }
    
    if (bedroomMove.find("ON THE BED")!= string::npos)
    {
      cout<<"The key is not on the bed"<<endl;
      global ++;
    }
    else if(bedroomMove.find("UNDER THE BED")!=string::npos)
    {
      cout<<"The key is not under the bed"<<endl;
      global ++;
    }
    
    else if(bedroomMove.find("IN THE TRUNK")!=string::npos)
    {
      system("clear");
      updateScoreSQL(global);
      keyfound();
      return 0;
      break;
    }
    
     else if (bedroomMove.find("ON THE TRUNK")!=string::npos)
     {
       cout<<"The key is not on the trunk"<<endl;
       global ++;
     }
     else if (bedroomMove.find("LEAVE")!=string::npos || bedroomMove.find("EXIT")!=string::npos)
     {
       cout<<"You have now left the first bedroom"<<endl;
       global ++;
       system("clear");
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


int upstairs()
{
  string UpstairsMove;
  bool leaveRoom = false;
  upstairsHallway();

  
  while (leaveRoom==false)
  {
    if (getline(cin,UpstairsMove))
           {transform(UpstairsMove.begin(), UpstairsMove.end(), UpstairsMove.begin(), ptr_fun<int, int>(toupper));
    }
    if (UpstairsMove.find("BEDROOM") != string::npos)  
    {
      global ++;
      system("clear");
      bedRoom();
    }
    else if (UpstairsMove.find("LEAVE") != string::npos|| UpstairsMove.find("EXIT")!=string::npos || UpstairsMove.find("DOWNSTAIRS")!=string::npos)
    {
      cout << "You are now back downstairs" << endl;
      global ++;
      system("clear");
      mainRoom();
      return 0;
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
