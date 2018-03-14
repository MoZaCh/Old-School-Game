#include <iostream>
#include <limits>
#include <unistd.h>

using namespace std;

#include "libsqlite.hpp"


//Insert into Function -- Name
bool SQL(int mageHealth, int mageMana,int enemyHealth)
{
  
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO combat (MageHP, MageMana, EnemyHP) "
                 "VALUES (?, ?, ?);"); //sql command
    cur->prepare(); //Sends to database
    cur->bind(1, mageHealth);
    cur->bind(2, mageMana);
    cur->bind(3, enemyHealth);
    cur->step();
  }
  
  catch (sqlite::exception e)
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}
