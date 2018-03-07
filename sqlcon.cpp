#include <iostream>
#include <limits>
using namespace std;

#include "libsqlite.hpp"

//Insert into Function -- Name and Class
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

//print results in database
void printResults()
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from users"); //sql command
  cur->prepare(); //sends to database

  
  while(cur->step())
  {
    cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << endl;//" |Class: " << cur->get_text(2) << endl;
  }

}



bool nameCheck( string name, bool nameUsed)
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from users"); //sql command
  cur->prepare(); //sends to database

  
  while(cur->step())
  {
    //cout << "ID: " << cur->get_int(0)<< " |Username: " <<  cur->get_text(1) << " |Class: " << cur->get_text(2) << endl;
  
    //int count = cur->get_int(0);
    //cout << count << endl;
    
    
    if (cur->get_text(1) == name)
    {
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
    cout << "Username has already inuse" << endl;
    nameUsed = true;
    return nameUsed;
  }
  else
  {
    cout << "Welcome New User!!!!" << endl;
    nameUsed = false;
    return nameUsed;
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


void selectSQL()
{
  sqlite::sqlite db("testdb.db");
  auto cur = db.get_statement();
  
  cur->set_sql("SELECT username)"
               "FROM users"
               "WHERE class = 'Mage';"); //sql command
  cur->prepare();
  //cur->bind(1, gen);
  cur->step();
  string count = cur->get_text(1);
  cout << count << endl;
}



int main()
{
  
  bool nameUsed = true;
  while (nameUsed == true)
  {
    string name;
    cout << "Enter a username: ";
    cin >> name;
    bool ans = nameCheck(name, nameUsed);
    if (ans == false)
    {
      insertNameSQL(name);
      break;
    }
          
  }
  
  printResults();
  //path();
}
