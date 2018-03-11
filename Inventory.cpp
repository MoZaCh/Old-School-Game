#include<iostream>
#include <string>
#include <vector>
#include <fstream>

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
    cout << "----------------------------------------------------------" << endl;
	cout<<"1. Inventory \n2. Exit\n";
    cout << "----------------------------------------------------------" << endl;
	cin>> Inventory;
	cout<<endl;
	 
	
	Begin:
	if (Inventory == 1 )
  {
	 
		 vector <string> inventory {"Twig"};
        
      ifstream  stream1("Items.txt"); //Locates File
    string line ;

    while( std::getline( stream1, line ) )
    {
        if(line.find("Crusty Crossbow") != string::npos) // Will search for item in file
        { 
             inventory.push_back("Crusty Crossbow");
        }
        else if (line.find("Potions x2") != string::npos)// Will search for Priest in file
        {
           inventory.push_back("Potions x2");
        }
         else if (line.find("Map") != string::npos)// Will search for Priest in file
        {
           inventory.push_back("Map");
        }
    }
        Start:
         if (inventory.size() == 0)
		      {		
		       cout<<"Inventory Empty\n";
			    }
        else 
        {
         for (string i : inventory)
             cout<<i<<endl;
        }
		
	   while( true)
	    {	
			cout << endl;
	     cout<< "\n1. Drop items\n2. Exit\n" ;
           cout << endl;
	     cin >> choice;
		
	     switch (choice)
	     {
		    
			 		 
        case '1' :
						  DropItem:
                 cout << endl;
				 cout<<"What Items do you want to Drop ? \n";
                 cout << endl;
                 
                  for( int i =0;i< inventory.size();i++)
	  {
		 cout<<i<<". "<<inventory[i]<<endl;}
                 cout << endl;
			   cin>>index;
                 if (inventory.size() < index)
                 {
                     cout << endl;
                     cout << "-------------------------------------" << endl;
                     cout << "         Item Doesnt Exist!" << endl;
                     cout << "-------------------------------------" << endl;
                     cout << endl;
                     goto DropItem;
                 }
         inventory.erase(inventory.begin()+ index);
				 { 
					
          cout <<"You dropped an Item" <<endl;
                     cout << endl;
             
				 }
			    goto Start;
			  				
		    
			 		
	      case '2' :
			 
				 return 0;
			   
			 					
		    default:
					 
				 system("clear");
				 cout<<"Not a valid option"<<endl;
                 cout << endl;
			    goto Begin;
			 }
			
		 if (inventory.size()>10)
		  {			
			 system("clear");
             cout << endl;
		   cout<<"Inventory Full\n";		
             cout << endl;
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
     cout << endl;
     return main();
  }
}
