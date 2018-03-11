#include<iostream>
#include <string>
#include <vector>

using namespace std ;

int main ()
{
	cout << R"(
       ___
       )_(                                            _
       | |                                           [_ ]
     .-'-'-.       _                               .-'. '-.
    /-::_..-\    _[_]_                            /:;/ _.-'\
    )_     _(   /_   _\      [-]                  |:._   .-|
    |;::    |   )_``'_(    .-'-'-.       (-)      |:._     |
    |;::    |   |;:   |    :-...-:     .-'-'-.    |:._     |
    |;::    |   |;:   |    |;:   |     |-...-|    |:._     |
    |;::-.._|   |;:.._|    |;:.._|     |;:.._|    |:._     |
    `-.._..-'   `-...-'    `-...-'     `-...-'    `-.____.-'    
    )" << endl;

	
	char choice;
	int index;
	int number;
	int Inventory;
	cout<<"1. Inventory \n2. Exit\n";
	cin>> Inventory;
	cout<<endl;
	 
	
	Begin:
	if (Inventory == 1 )
  {
	 vector <string> items = {"","sword", "axe","bow","antidoes"}  ;
	 for( int i =1;i< items.size();i++)
	  {
		 cout<<i<<". "<<items[i]<<endl;}
		 vector <string> inventory {"",} ;
		
	   while( true)
	    {	
			
	     cout<< "\n1. Add items \n2. Drop items \n3. Show items \n4. Exit\n" ;
	     cin >> choice;
		
	     switch (choice)
	     {
		    case '1':					
						 
			   cout<<"Enter item number: \n";
			   cin>>number;
			   inventory.insert(inventory.begin()+1,items[number]);
				 cout<<"you picked "<<items[number]<<endl;			
			   break;
			 		 
        case '2' :
						  
				 cout<<"what items do you want to drop ? \n";
			   cin>>index;
         inventory.erase(inventory.begin()+ index);
				 { 
					vector<string>::iterator it = inventory.begin()+index;  
          cout <<"you dropped "<< *it<<endl;
				 }
			    break;
			  				
		    case '3' :
					 
		  	 cout<<endl;
			   if (inventory.size() == 1)
		      {		
		       cout<<"Inventory Empty\n";
			    }
	   
				 for( int i =1;i< inventory.size();i++)
		      {
		       	cout<<i<<". "<<inventory[i]<<endl;
				  }
			     break;
			 		
	      case '4' :
			 
				 return main ();
			   break;
			 					
		    default:
					 
				 system("clear");
				 cout<<"Not a valid option"<<endl;
			    goto Begin;
			 }
			
		 if (inventory.size()>10)
		  {			
			 system("clear");
		   cout<<"Inventory Full\n";			
		  }
	 }  
  }
	
 else if (Inventory == 2 )
	{
	 return 0;
	}
	
 else
  {
	  system("clear");
    cout << "Invalid Entry. Must be 1 or 2" << endl; 	  
  }
}
