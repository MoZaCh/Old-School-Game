#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Paths.cpp"
using namespace std;


int credits()
{
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

int main()
{ 
  while (true)
  {
  cout <<"\n===========================================\n"<<
          "T i t l e\n"<<
          "===========================================\n"<<endl;
  
  cout<< "1) Start New Game\n"<<
         "2) Resume Game\n"<<
         "3) Credits\n"<<
         "4) Exit"<<endl;
  cout<< "\nSelect an option: ";
  char choice;
  cin>> choice;
    
  switch (choice)
  {
  case '1': //Start New Game
          system("clear");
          path();
  break;
  
  case '2': // Resume Game
  break;
  
  case '3':
  credits();
  break;
  
  case '4':
          system("clear");
  return 0;
  
  default:
                
  cout<< "Wrong choice, try again: ";
                system("clear");
  }
    
  }
  return 0;
}
