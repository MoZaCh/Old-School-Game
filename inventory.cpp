# include<iostream>
#include <string>
#include <vector>
#include <array>

using namespace std ;

int main ()
{
	
	char choice;
	int index;
	int number;
	string Inventory;
	Start:
	cout<<"1. Show Inventory Inventory \n";
	cin>> Inventory;
	 
	
	Begin:
	if (Inventory == "1")
	{
		vector <string> items = {"","sword", "axe","bow","antidoes"}  ;
   
	   for( string i : items)
		  cout<<i<<endl;
		vector <string> inventory ;
		
		
	  while( true)
	  {	
			
	    cout<< "\n1. Drop items \n2. Exit\n" ;
	    cin >> choice;
		
	    switch (choice)
	    {
			
			 
       case '1' :
			
			  
				 cout<<"what items do you want to drop ? \n";
			   cin>>index;
         inventory.erase(inventory.begin()+ index);
			   break;
			  
				
			
			
	     case '2' :
			 
				 return main ();
			   break;
			 
					
		   default:
					system("clear");
					cout<<"Not a valid option"<<endl;
			    goto Begin;
			 			
	     }
		if (inventory.size()>5)
		{			system("clear");
		     cout<<"Inventory Full\n";}
	   
    }
  }
    else
    {
        Inventory.clear();
        cout << "Invalid Entry. Must be 1" << endl;
        goto Start;
    }
return 0;
}
