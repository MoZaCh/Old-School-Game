#include<iostream>
#include <string>
#include <vector>

using namespace std ;

#include "libsqlite.hpp"
//Insert into Function -- Name
bool insertNameSQL(string InventoryItems)
{
  
  
  try //try statement do this unless error occurs 
  {
    sqlite::sqlite db("testdb.db"); //Connecting to Database
    auto cur = db.get_statement(); //Creates a cursor on this connection
  
    cur->set_sql("INSERT INTO Inventory (InventoryItems) VALUES (?);"); //sql command
    cur->prepare(); //Sends to database
		cur->bind(1, InventoryItems);
    cur->step();
  }
  
  catch (sqlite::exception e) //Catching the sqlerror to avoid the program to crash
  {
    cerr << e.what() << endl;
    return 1;
  }
  return 0;
}


int main ()
{
	while (true)
  {
// Starting Screen	
// Taken from website https://codereview.stackexchange.com/questions/172170/ascii-text-based-rpg-game-in-c
// Because it suites my inventory
	
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
		
			// variable decalared for input

			char Inventory;
			int index;
			int number;
			char choice;

			
			// Choice to open inventory or exit
			
			cout<<"-------------------------------------------------------------"<<endl;	
			cout<<"1. Inventory \n2. Exit\n";
			cout<<"-------------------------------------------------------------"<<endl;
			cin>> choice;
			cout<<endl;

			// Open inventory
			
			begin:
			if (choice =='1' )
        {
				
					// All items in the game
					
				 vector <string> items = {"","Crusty Crossbow", "Potions x2","Wand","Blunt Axe","Teared Talisman","Feeble Staff","Twig","Antidoes","Leather Tunic","Sword","Flack Jacket","Bow","Halberk"}  ;	 

				 // Items in the inventory
				 // Inventory Holds 10 items
				 vector <string> inventory {"","Sword","Crusty Crossbow"} ;

				  while( true)
						{	
						 // Functions in the inventory
						 
						 cout<<endl;
						 cout<<"-------------------------------------------------------------"<<endl;
						 cout<< "1. Show items \n2. Add items \n3. Drop items \n4. Exit\n" ;
						 cout<<"-------------------------------------------------------------"<<endl;
						 cin >> Inventory;

						 switch (Inventory)
						 {
								 // Function displays items present in inventory
								
							 case '1' :
                
							 cout<<endl;
								 
								 // Checks whether the Inventory is empty 
							 if (inventory.size() == 1)
								{		
								 // Display message
								 
								 cout << endl;
								 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
								 cout<<"             Inventory Empty\n";
								 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
								cout << endl;

								}
								 // Display items present in inventory
								cout<<endl;
							  cout<<"``````````````````````````````````````````````````````````````"<<endl; 
								cout<<endl;
								cout<<"Items in Inventory"<<endl;
								cout<<endl;
								for( int i =1;i< inventory.size();i++)
								 {
									cout<<i<<". "<<inventory[i]<<endl;
									insertNameSQL(inventory[i]);
								 }
								 cout<<endl;
								 cout<<"``````````````````````````````````````````````````````````````"<<endl;
								 cout<<endl;
								 break;

							case '2':
								 
										 // Function to add items in the inventory
									 AddItem:

										 //Display all items present in the game

										 cout<<endl;
										 cout<<"``````````````````````````````````````````````````````````````"<<endl;
										 cout<<endl;
										 cout<<"List of Items"<<endl;
										 cout<<endl;
									 for( int i =1;i< items.size();i++)
										 {
											cout<<i<<". "<<items[i]<<endl;
										 }	
											 cout<<endl;
											 cout<<"``````````````````````````````````````````````````````````````"<<endl;
											 cout<<endl;
											 cout<<"Enter Item number that you want to add in inventory: \n";
											 cin>>number;

									 // Checks input whether it is string instead of number

										 while(cin.fail())
											{  
												 // Clears the terminal

												 system("clear");

												 // clears the error flag
												 cin.clear();
												 //skips to the next newline
												 cin.ignore(256, '\n');

													// Display error message

												 cout << endl;
												 cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
												 cout << "              Invalid input!  Try again." << endl;
												 cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
												 cout << endl;

												 //Recalls the function

												 goto AddItem;

													}
										// Checks input whether it is 0 as it is already empty in the vector

										if( number == 0)
										 {
												// Display error message
												cout << endl;
												cout << "*************************************" << endl;
												cout << "         Item Doesnt Exist!" << endl;
												cout << "*************************************" << endl;
												cout << endl;

											 //Recalls the function
												goto AddItem;
											}

											 // Checks input whether it is greater than 14 
											 // As there are only 13 items in the game
											else if( number > 13)
												{
                         // Display error message
										  	 cout << endl;
												 cout << "*************************************" << endl;
												 cout << "         Item Doesnt Exist!" << endl;
												 cout << "*************************************" << endl;
												 cout << endl;
											
											 	 //Recalls the function
												 goto  AddItem;
										  }

									   else
									     {
												// Inserts specfic items in the inventory from multiple items in the game
												 
										    inventory.insert(inventory.begin()+1,items[number]);
										    cout << endl;
												
												 // Display name of the item which is added in the inventory
									 
									       cout<<"You picked "<<items[number]<<endl;
												}
												 break;

                  case '3' :
								 
								     // Function to delete items in the inventory
								 
										 DropItem:
								  
								    // Display items present in inventory
										 cout<<endl;
										 cout<<"``````````````````````````````````````````````````````````````"<<endl;
										 cout<<endl;
										 cout<<"Items in Inventory"<<endl;
										 cout<<endl;
                      
									   for( int i =1;i< inventory.size();i++)
										  {
											 cout<<i<<". "<<inventory[i]<<endl;
										  }
										 cout<<endl;
									   cout<<"``````````````````````````````````````````````````````````````"<<endl;
									   cout<<endl;
									   cout<<"Enter Item number that you want to drop: \n";
									   cin>>index;
								  
								     // Checks input whether it is string instead of number
								     
										 while(cin.fail())
											 {
													system("clear");
													cin.clear();
													cin.ignore(256, '\n');
													cout << endl;
													cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
													cout << "              Invalid input!  Try again." << endl;
													cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
													cout << endl;
													goto DropItem;

													}
								        // Checks  whether the inventory is empty 
											 if (inventory.size() == 1)
												{	
												 // Display message
												 cout << endl;
												 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
												 cout<<"             Inventory Empty\n";
												 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
												 cout << endl;
												}
								 
								        // Checks input whether it is 0 as it is already empty in the vector
											 else if( index == 0)
													{
                             // Display error message
														cout << endl;
														cout << "*************************************" << endl;
														cout << "         Item Doesnt Exist!" << endl;
														cout << "*************************************" << endl;
														cout << endl;
                            //Recalls the function
														 goto DropItem;
													}
								       // Checks input whether it is greter than number of items in the inventory
										   else if( inventory.size() < index)
														{

															 cout << endl;
															 cout << "*************************************" << endl;
															 cout << "         Item Doesnt Exist!" << endl;
															 cout << "*************************************" << endl;
															 cout << endl;
															 goto DropItem;
														}

											 else
												 { //deletes specific item from the inventory
													 inventory.erase(inventory.begin()+index);	
													 cout << endl;
												  //Display message
													 cout <<"You dropped an Item "<<endl;
												 }
												break;



										case '4' :
								      // Exit from the inventory	
										 system("clear");
								     //Starts from the begining
										 return main ();
										 break;

										default:
                      //Enters anything else rather chosing any function       
										 system("clear");
								     //Display message
										 cout << endl;
										 cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
										 cout<<"                    Invalid Entry"<<endl;
										 cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
										 cout << endl;

											 break;
									 }
									 //Checks inventory if it is more than 10 items
									 if (inventory.size()>11)
										{			
										 //Display message
										 cout << endl;
										 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
										 cout<<"           Inventory Full\n";
										 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
										 cout << endl;
											// Takes exit as it tries to add more items in the inventory 
										 return 0 ;
										}
				   }  
        }

		 else if (choice == '2')
			{
			 system("clear");
			 //Exit from the Inventory
			 return 0;
			}

		 else
			 {//Enters anything else rather than selecting choices
				system("clear");
				cout << endl;
				cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
				cout << "         Invalid Entry. Must be 1 or 2" << endl; 	
				cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
				cout << endl;
		   }
   }
}
	
