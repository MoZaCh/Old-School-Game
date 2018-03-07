#include <iostream>
#include <limits>
using namespace std;

#include "libsqlite.hpp"


//Insert into Function -- Name
void insertNameSQL(string name)
{
  sqlite::sqlite db("testdb.db");
  auto cur = db.get_statement();
  
  cur->set_sql("INSERT INTO users (username) "
               "VALUES (?);"); //sql command
  cur->prepare();
  cur->bind(1, name);
  cur->step();
}

// SQL delete a username from the databate
void deleteSQLdata(string name)
{
  cout << name << endl;
  sqlite::sqlite db("testdb.db");
  auto cur = db.get_statement();
  
  cur->set_sql("DELETE "
               "FROM users "
               "WHERE username = ?;"); //sql command
  cur->prepare();
  cur->bind(1, name);
  cur->step();
}


//Print results in database
void printResults()
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from users"); //sql command
  cur->prepare(); //sends to database

  
  while(cur->step())
  {
    cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << endl;
  }
}


//Overwrite function 
bool overWrite(string name)
{
  string writeAns;
  cout << "Would you like to overwrite? (Y/N)" << endl;
  cin >> writeAns;
  
  if (writeAns == "Y" || writeAns == "y")
  {
    cout << "Overwrite Complete" << endl;
    return false;
  }
  
  else
  {
    cout << "Please enter a different username!" << endl;
    return true;
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
               "from users"); //sql command
  cur->prepare(); //sends to database

  
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
    cout << "Username already inuse!" << endl;
    ans1 = overWrite(name);
    return ans1;
  }
  else
  {
    cout << "Welcome New User!!!!" << endl;
    return false;
  }
  return 0;
}


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


//Select into Function -- Name
void selectaNameSQL(string name)
{
  sqlite::sqlite db("testdb.db");
  auto cur = db.get_statement();
  
  cur->set_sql("INSERT INTO users (class) "
               "VALUES (?) "
               "WHERE username = ?;"); //sql command
  cur->prepare();
  cur->bind(1, name);
  cur->step();
}



int main()
{
  bool nameUsed = true;
  while (nameUsed == true)
  {
    string name;
    cout <<"Enter Username: " << endl;
    cin >> name;
    bool ans = nameCheck(name, nameUsed);
    if (ans == false)
    {
      deleteSQLdata(name);
      insertNameSQL(name);
      break;
    }
          
  }
  
    sleep(2);
    system("clear");
  
}
