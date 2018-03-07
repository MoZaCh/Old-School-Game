# include<iostream>
#include <string>
#include <vector>
using namespace std ;

int main ()
{
	
	char choice;
	int index;
	string name;
	int Inventory;
	
	cout<<"2. Inventory \n";
	cin>> Inventory;
	
	
	if (Inventory == 2)
	{
		vector <string> inventory;
		
	  while( true)
	  {	
			Begin:
	    cout<< "1. Add items \n2. Drop items \n3. Show items \n4. Exit\n" ;
	    cin >> choice;
		
	    switch (choice)
	    {
		   case '1':					
			
			 
			 cout<<"Enter item name: \n";
			 for( int count=0; count<5; count++ )
			 {cin>>name;
			 inventory.push_back(name);}
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
					cout<<"Not a valid option"<<endl;
			 goto Begin;
			 			
	   }	
	 }
 }
	 return 0;
}
