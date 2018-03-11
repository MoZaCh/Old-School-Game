#include <iostream>
#include <limits>
#include <unistd.h>
//#include "game.cpp"
using namespace std;

#include "libsqlite.hpp"


//Insert into Function -- Name
bool insertNameSQL(string name)
{
  string unknownClass = "unknown";
  int noScore = 0;
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO users (username, class, score) "
                 "VALUES (?, ?, ?);"); //sql command
    cur->prepare(); //Sends to database
    cur->bind(1, name);
    cur->bind(2, unknownClass);
    cur->bind(3, noScore);
    cur->step();
  }
  
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}

// SQL delete a username from the databate
bool deleteSQLdata(string name)
{
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("DELETE "
                 "FROM users "
                 "WHERE username = ?;"); //sql command
    cur->prepare(); //Sends to database
    cur->bind(1, name);
    cur->step();
    
  }
  
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}

//Print all results from database
void printResults()
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from users"); //SQL command
  cur->prepare(); //Sends to database

  
  while(cur->step())
  {
    cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << " |class: " << cur->get_text(2) << endl;
  }
}


//Overwrite function 
bool overWrite(string name)
{
  string writeAns;
    
    choice:
    
  cout << "Would you like to overwrite? (Y/N)" << endl;
    cout << endl;
    
    
  cin >> writeAns;
  
  if (writeAns == "Y" || writeAns == "y")
  {
      cout << endl;
    cout << "Overwrite Complete" << endl;
      cout << endl;
    sleep(2);
    cout << "Welcome " << name <<  "!!!!" << endl;
      cout << endl;
      sleep(2);
    return false;
  }
  
  else if (writeAns == "N" || writeAns == "n")
  {
      cout << endl;
    cout << "Please enter a different username!" << endl;
      cout << endl;
    return true;
  }
    else
    {
        cout << endl;
    cout << "Invalid Input! Must be a Y or an N!" << endl;   
        writeAns.clear();
        cout << endl;
        goto choice;
    }
  
}


//Looping through the database
bool nameCheck( string name, bool nameUsed)
{
  int userId;
  bool nCheckans;
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from users"); //SQL command
  cur->prepare(); //Sends to database

  
  while(cur->step())
  {
    //cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << endl;
  
    if (cur->get_text(1) == name)
    {
      userId =  cur->get_int(0);
      nameUsed = true;
      break;
    }
    
    else
    {
      nameUsed = false;
    }
    
  }
  
  if (nameUsed == true)
  {
    cout << endl;
    cout << "Username already inuse!" << endl;
    cout << endl;
    nCheckans = overWrite(name);
    return nCheckans;
  }
  else
  {
    cout << endl;
    cout << "Welcome New User!!!!" << endl;
    cout << endl;
    sleep(2);
    cout << "Hi " << name << "," << endl;
    sleep(2);
    return false;
  }
  return 0;
}


int selectID(string name)
{
  try
  {
    sqlite::sqlite db( "testdb.db" ); //Opens the connection
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("SELECT id "
                 "FROM users "
                 "WHERE username = ?;"); //SQL command
    cur->prepare(); //Sends to database
    cur->bind(1, name);
    cur->step();
  
    return cur->get_int(0);
  }
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
}


//Updata tuple in DB Function
void selectaNameSQL(string name, int id)
{
  sqlite::sqlite db("testdb.db"); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("UPDATE users SET username = (?)"
               "WHERE id = ?;"); //SQL command
  cur->prepare(); //Sends to database
  cur->bind(1, name);
  cur->bind(2, id);
  cur->step();
}



int sqlcon()
{
  bool nameUsed = true;
  int gameMode, id;
  string name;
  while (nameUsed == true)
  {
    //string name;
    cout <<"Enter Username: " << endl;
    cout << endl;
    cin >> name;
    bool ans = nameCheck(name, nameUsed);
    if (ans == false)
    {
      deleteSQLdata(name);
      insertNameSQL(name);
      break;
    }
          
  }
  
  id = selectID(name);
  //cout << id << endl;
  
  while(true)
  {
    cout << "**Please choose a game mode (1/2)**" << endl;
    cout << endl;
    cout << "1 - Story Mode" << endl;
    cout << "2 - Challenge Mode" << endl;
    cin >> gameMode;
    
    if (gameMode == 1)
    {
      cout << "Loading Story Mode..." << endl;
      for (int i = 0; i <= 100; i+=10)
      {
        cout << i << "%" << endl;
        sleep(1);
      }
      break;
    }
    else if (gameMode == 2)
    {
      cout << "Loading Challenge Mode..." << endl;
      for (int i = 0; i <= 100; i+=10)
      {
        cout << i << "%" << endl;
        sleep(1);
      }
      system("clear");
      //mainGame();
      break;
    }
    else
    {
      cout << "Invalid option!" << endl;
      cout << endl;
    }
  }
  //printResults();
  system("clear");
  return id;
}
