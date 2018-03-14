#include <iostream>
#include <limits>
#include <unistd.h>

///Makesure to include the line below in your .cpp file////
#include "libsqlite.hpp"

using namespace std;

////FOR INSERTING DATA INTO THE DATABASE
bool insertNameSQLAlex()
{
  string name = "test1";
  int storyScore = 0;
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO StoryScore (name, storyScore) "
                 "VALUES (?, ?);"); //sql command
    cur->prepare(); //Sends to database
    cur->bind(1, name);
    cur->bind(2, storyScore);
    cur->step();
  }
  
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}

//PRINTING ALL RESULTS FROM THE DATABASE
void printResults()
{
  sqlite::sqlite db( "testdb.db" ); //Opens the connection
  auto cur = db.get_statement(); //Creates a cursor on this connection
  
  cur->set_sql("select *"
               "from StoryScore"); //SQL command
  cur->prepare(); //Sends to database

  
  while(cur->step())
  {
    cout << "ID: " << cur->get_int(0)<< " |Storyname: " <<  cur->get_text(1) << " |Score: " << cur->get_int(2) << endl;
  }
}




int main()
{
    insertNameSQLAlex();
    cout << "finish" << endl;
    printResults();
}
