#include <iostream>
#include <limits>
using namespace std;
#include "libsqlite.hpp"

//Insert into Function -- Name
bool insertToCombat(int mageHealth, int mageMana,int enemyHealth)
{
  
  try
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO Combat (MageHP, MageMana, EnemyHP) "
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

  
void showCombatResults()
{
  sqlite::sqlite db( "testdb.db" );
  auto cur = db.get_statement(); 
  
  cur->set_sql("select *"
               "from Combat"); //selects the table in order to print out the results
  cur->prepare(); 

  
  while(cur->step())
  {
    cout << "ID: " << cur->get_int(0)<< " |MageHP: " <<  
      cur->get_int(1) << " |MageMana: " << cur->get_int(2) << " |EnemyHP: "<< 
      cur->get_int(3)<<endl;
  }
}

bool deleteFromCombat()
{
  try //try statement do this unless error occurs 
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    
    char question;
    cout<<"What would you like to delete from Combat table?\n"<<
          "1) Mage losses \n 2) Enemy losses \n 3) Delete everything"<<endl;
    cout<<"Choice: ";
    cin>>question;
    
    
    if (question == '1'){
      auto cur = db.get_statement(); //Creates a cursor on this connection
      cur->set_sql("DELETE "
                 "FROM Combat "
                 "WHERE MageHP = 0;"); //sql command
      cur->prepare(); //Sends to database
      cur->step();
    }
    
    else if(question == '2'){
      auto cur = db.get_statement(); //Creates a cursor on this connection
      cur->set_sql("DELETE "
                 "FROM Combat "
                 "WHERE EnemyHP = 0;"); //sql command
      cur->prepare(); //Sends to database
      cur->step();
    }
    
    else{
      auto cur = db.get_statement(); //Creates a cursor on this connection
      cur->set_sql("DELETE "
                 "FROM Combat "
                  "WHERE id > 0;"); //sql command
      cur->prepare(); //Sends to database
      cur->step();
    }
       
}
 catch (sqlite::exception e) //Catching the sql error to avoid program from crashing
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}
  
