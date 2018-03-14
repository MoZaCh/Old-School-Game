#include <iostream>
#include <limits>
#include <unistd.h>
#include "Combat.cpp"
#include "libsqlite.hpp"

using namespace std;

////INSERTING DATA INTO DATABASE
bool insertNameSQLAlex()
{
  string name = "test1";
  if(storyScore <= 0) storyScore = 0;
  try
  {
    sqlite::sqlite db("testdb.db"); //connecting to the database
    auto cur = db.get_statement(); //creating a cursor
  
    cur->set_sql("INSERT INTO StoryScore (name, storyScore) "
                 "VALUES (?, ?);"); //creates a table and adds values
    cur->prepare(); //Sends the data to the database
    cur->bind(1, name);//binding placeholder nr1 to the name variable
    cur->bind(2, storyScore);//binding placeholder nr2 to the score variable
    cur->step();
  }
  
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}

////DATABASE TABLE PRINT FUNCTION
void printResults()
{
  sqlite::sqlite db( "testdb.db" );
  auto cur = db.get_statement(); 
  
  cur->set_sql("select *"
               "from StoryScore"); //selects the table in order to print out the results
  cur->prepare(); 

  
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
