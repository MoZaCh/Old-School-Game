#include<iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std ;

int inventory()
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
	
    cout << "----------------------------------------------------------" << endl;
	
    
	
	cout<<endl;
	 
	
	Begin:
	
  {
	 
		 vector <string> Inventory { };
        
      ifstream  stream1("Items.txt"); //Locates File
    string line ;

    while( std::getline( stream1, line ) )
    {
        if(line.find("Crusty Crossbow") != string::npos) // Will search for item in file
        { 
             Inventory.push_back("Crusty Crossbow");
        }
        else if (line.find("Potions x2") != string::npos)// Will search for Priest in file
        {
           Inventory.push_back("Potions x2");
        }
         else if (line.find("Map") != string::npos)// Will search for Priest in file
        {
           Inventory.push_back("Map");
        }
        else if (line.find("Wand") != string::npos)// Will search for Priest in file
        {
           Inventory.push_back("Wand");
        }
        else if (line.find("Blunt Axe") != string::npos)// Will search for Priest in file
        {
           Inventory.push_back("Blunt Axe");
        }
        else if (line.find("Teared Talisman") != string::npos)// Will search for Priest in file
        {
           Inventory.push_back("Teared Talisman");
        }
        else if (line.find("Feeble Staff") != string::npos)// Will search for Priest in file
        {
         Inventory.push_back("Feeble Staff");
        }
        else if (line.find("Twig") != string::npos)// Will search for Priest in file
        {
         Inventory.push_back("Twig");
        }
        
        
    }
        Start:
         if (Inventory.size() == 0)
		      {		
		       cout<<"Inventory Empty\n";
			    }
        else 
        {
         for (string i : Inventory)
             cout<<i<<endl;
        }
      cout << endl;
      cout << "----------------------------------------------------------" << endl;
		
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
                 
                  for( int i =0;i< Inventory.size();i++)
	  {
		 cout<<i<<". "<<Inventory[i]<<endl;}
                 cout << endl;
			   cin>>index;
                 if (Inventory.size() < index)
                 {
                     system("clear");
                     cout << endl;
                     cout << "-------------------------------------" << endl;
                     cout << "         Item Doesnt Exist!" << endl;
                     cout << "-------------------------------------" << endl;
                     cout << endl;
                     goto DropItem;
                 }
         Inventory.erase(Inventory.begin()+ index);
				 { 
					
          cout <<"You dropped an Item" <<endl;
                     cout << endl;
             
				 }
			    goto Start;
			  				
		    
			 		
	      case '2' :
			 system("clear");
				 return 0;
			   
			 					
		    default:
					 
				 system("clear");
				 cout<<"Not a valid option"<<endl;
                 cout << endl;
			    goto Begin;
			 }
			
		 if (Inventory.size()>10)
		  {			
			 system("clear");
             cout << endl;
		   cout<<"Inventory Full\n";		
             cout << endl;
		  }
	 }  
  }
	system ("clear");
}
