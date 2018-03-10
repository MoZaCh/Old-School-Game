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
	int Inventory;
	
	cout<<"2. Inventory \n";
	cin>> Inventory;
	 
	
	Begin:
	if (Inventory == 2)
	{
		vector <string> items = {"","sword", "axe","bow","antidoes"}  ;
   
	   for( string i : items)
		  cout<<i<<endl;
		vector <string> inventory ;
		
		
	  while( true)
	  {	
			
	    cout<< "1. Add items \n2. Drop items \n3. Show items \n4. Exit\n" ;
	    cin >> choice;
		
	    switch (choice)
	    {
		   case '1':					
			
			 
			 cout<<"Enter item number: \n";
			 cin>>number;
			 inventory.insert(inventory.begin(),items[number]);
				
			
			 break;
			 
			
			 
       case '2' :
			
			  
				 cout<<"what items do you want to drop ? \n";
			   cin>>index;
         inventory.erase(inventory.begin()+ index);
			   break;
			  
				
		   case '3' :
			
			 
				for (string i : inventory)
		    cout<<"you picked "<<i<<endl;
			  break;
			 
			
			
	     case '4' :
			 
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
return 0;
}
