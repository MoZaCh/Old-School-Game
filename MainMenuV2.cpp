#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Paths.cpp"
using namespace std;

int main()
{ 

  title:
  cout <<"\n===========================================\n"<<
          "T i t l e\n"<<
          "===========================================\n"<<endl;
  
  cout<< "1) Start New Game\n"<<
         "2) Resume Game\n"<<
         "3) Credits\n"<<
         "4) Exit"<<endl;
  cout<< "\nSelect an option: ";
  string choice;
      option:
  cin>> choice;
    
  if (choice == "1") //Start New Game
  {
          system("clear");
          path();
  }
  
  else if (choice == "2") // Resume Game
  {
      cout << endl;
      cout << "Unfinished\n" << endl;
      goto title;
  }
  
  else if (choice == "3")
  {
      choice.clear();
      
  string choice; 
      
 system("clear");
      
    Choice:
      
  cout<<"Credits:\n"<<
        "------------------------------------ \n"<<
        "*KHAN Qais* \n"<<
        "*LAWAL Paul* \n"<<
        "*ASAVKINAS Aleksandras* \n"<<
        "*MAREK Peter* \n"<<
        "*CHOUDHURY Mohammed Zahed* \n"<<
        "*PATEL Harshkumar Chandrakant* \n"<<
        "------------------------------------"<<endl;
  cout<< "Would you like to go back? (Y/N): ";
  cin>>choice;
  
  if (choice=="Y" || choice=="y")
  {
    system("clear");
      goto title;
  }
      
  else if (choice == "N" || choice == "n")
  {
      system("clear");
    exit(0);
  }
      
    else
    {
        cout << "Invalid Input! Must Answer with Y or N" << endl;
       goto Choice; 
    }
      
  }
  
  else if (choice == "4")
  {
          system("clear");
  return 0;
  }
  
  else 
  {
  cout<< "Wrong choice, try again: ";
     choice.clear();
    goto option;
  }
  return 0;
}
