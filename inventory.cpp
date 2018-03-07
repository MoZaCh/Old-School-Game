#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;
int main()
{
  vector<string>inventory;
  vector<string>::iterator iter;
  user:
    
  cout << "What would you like to do?" << endl;
  cout << "1.Open Inventory \n2.Exit" << endl;
  string User;
    
  cin >> User;
  if (User == "1")
  {
    system("clear");
    for(iter = inventory.begin(); iter != inventory.end(); iter++)
    cout << *iter << "";
      string back;
      Back:
      cout << endl;
      cout << "Would you like to go back?\n1. Yes \n2. No" << endl;
      cin >> back;
          if (back == "1")
          {
              system("clear");
              goto user;
          }
      else if (back == "2")
      {
         system("clear");
      cout << "You have exited the program\n" << endl;
      return 0;
      }
      else
      {
          cout << endl;
      cout << "Invalid Input!" << endl;
          back.clear();
          goto Back;
      }
  }

  else if (User == "2")
    {
      system("clear");
      cout << "You have exited the program\n" << endl;
      return 0;
    }

    else
    {
        cout << endl;
        cout << "Invalid Input!" << endl;
            User.clear();
        cout << endl;
            goto user;
    }
 
  return 0;
}
