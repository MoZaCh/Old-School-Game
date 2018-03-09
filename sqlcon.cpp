#include <iostream>
#include <limits>
#include <unistd.h>
using namespace std;

#include "libsqlite.hpp"


//Insert into Function -- Name
bool insertNameSQL(string name)
{
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO users (username) "
                 "VALUES (?);"); //sql command
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
    cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << endl;
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
  bool ans1;
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
    ans1 = overWrite(name);
    return ans1;
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

//Inserts the chosen class information into DB
char chooseClass()
{
  char choice;

	do{

	cout << "Please choose a class type! \nMage (1) \nOption (2):"<< endl;
	cin >> choice;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
  
  while(choice != '1' && choice != '2' && choice != '3');
  {
    if (choice == '1')
    {
      cout << "You have chosen the Mage class" << endl;
      return choice;
    }
    else if (choice == '2')
    {
      cout << "You have chosen the opt 2 class" << endl;
      return choice;
    }
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



int main()
{
  bool nameUsed = true;
  while (nameUsed == true)
  {
    string name;
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
    cout << endl;
  //printResults();
  cout << "Loading game..." << endl;
  for (int i = 0; i <= 100; i+=10)
  {
    cout << i << "%" << endl;
    sleep(1);
  }
    system("clear");
	return 0;
}
