#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include "MergedClasses.cpp"
#include <ncurses.h>
#include "Inventory.cpp"
#include <curses.h>
#include "sqlcon.cpp"
#include "Combat.cpp"
#include "Finish.cpp"


using namespace std;


int main()
{
    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Twig\n";
              ;
              myfile.close();
    
    int userId = sqlcon();
    
cout << "You awake in a Cave, covered in gravel and dirt." << endl;
    
// sleep
    
cout << "You seem to not be able to remember much but you do gather your name." << endl;
 
    // sleep
    

    string name; //Variable
    
    string confirm; //Variable
    
    userName: //Loop thingy
    
     cout << "Please enter your name: " << endl; //Asks user for what their name would be
        cin >> name; //Input
    
    confirmCheck: //Loop Thingy
    cout << endl;
    cout << "Are you sure? Please enter y/n: " << endl; //Confirms if the user is sure
    cin >> confirm; //Input
    
    
    if (confirm == "Y" || confirm == "y") //Game Continues
    {
        cout << endl; //Input
        
        cout << "Your head is in a daze" << endl;
        // sleep
    }
    
    else if (confirm == "N" || confirm == "n") //Loops back to the name
    {
        name.clear(); //Clears Variable
        goto userName; //Loops Back
    }
    
    else 
    {
        cout << endl;
        cout << "*Invalid Input! Must be a Y/N answer*" << endl; //Error Check
        // sleep
        cout << endl; //New Line
        goto confirmCheck; // Loops Back
    }
    
    // sleep
    
    cout << "You try to concentrate your thoughts, \nJust trying to gather your thoughts is causing your head to pound." << endl;
    // sleep
    
    cout << "You're able to just about remember small things of your past, your remember that you are a... " << endl;
    
    classes(userId);
            
    
    
    cout << endl;
    // sleep
    //Link To Classes 
    cout << "You seem to see to be near the enterance of the cave" << endl;
    
    cout << "Do you explore the rest of the cave or leave the cave to try and find your way back home." << endl;
    
    string Cave;
    
    cave: //Loop Thing
    
    cout << "Stay in the Cave. \nLeave the Cave." << endl;
    cout << endl;
    
    cout << "- Stay. \n- Leave.\n- Open Inventory" << endl;
    cin >> Cave;
        
   if (Cave == "stay" || Cave == "Stay")
   {
       cout << endl;
       cout << "You decide to stay in the cave to explore, maybe you'll be able to find some answer for why\nyou are in this cave and how you got here." << endl; //Stuff about cave
       cout << "As you venture through the cave you are finding it more difficult to see with each step" << endl;
       string caveStay;
       
       CaveStay: //Loop thingy
       
       cout << "Do you press on?\n\nYes.\nNo." << endl; 
       cin >> caveStay;
       
       if(caveStay == "Yes" || caveStay == "yes" || caveStay == "Y" || caveStay == "y") //confirming answer
       {
           cout << endl;
           cout << "You keep going, you keep taking a step further into the darkness.\nAt this point you are completely shrouded in darkness, you aren't able to see a single thing,\nBut you continue to venture onward, you end up hitting a wall.\nYou're able to feel a breeze on the other side and are even able to see a crack of light behind the rocks." << endl;
           cout << endl;
           cout << "You try to chip away at the rocks, finding it with ease like these rocks have been moved a lot.\nyou discover something hidden behind them, it seems to be some type of small room, lit up by just one torch.\nthere is a pedestal, there seems to be a weapon ontop, \nits a Ancient Artifact" << endl;
           cout << endl;
           cout << "You inspect the pedestal, you don't see anything strange about the pedestal other than it has some ancient hieroglyphics \non it which you arent able to read." << endl;
           cout << endl;
           cout << "But you can tell from the ingravings on the Artifact its self that it is," << endl;
           cout << endl;
           ifstream  stream1("classChoice.txt"); //Locates File
    string line ;

    while( std::getline( stream1, line ) )
    {
        if(line.find("Mage") != string::npos) // Will search for Mage in file
        { 
            cout << "Felo'melorn +  Heart of the Phoenix!" << endl; //Print Line that is read in file.
        }
        else if (line.find("Priest") != string::npos)// Will search for Priest in file
        {
            cout << "T'uure, Beacon of the Naaru!" << endl;
        }
        else if (line.find("Necromancer") != string::npos)// Will search for Necromancer in file
        {
            cout << "The Scepter of Sargeras!" << endl;
        }
        else if (line.find("Warrior") != string::npos)// Will search for Warrior in file
        {
            cout << "Strom'kar, the Warbreaker!" << endl;
        }
        else if (line.find("Hunter") != string::npos)// Will search for Hunter in file
        {
            cout << "Thas'dorah, Legacy of the Windrunners!" << endl;
        }
    }
        cout << endl;
        cout << "The ancient relic thought to be destroyed in the rune wars!" << endl;
        cout << endl;
        
           cout << "Do you wish to take the weapon?" << endl;
           
           TakeWeapon://Loop Thingy
           
           cout << endl;
           
           string takeWeapon;
           cout << "-Take the weapon and dive into possible dangers.\n-Leave it alone and find the exit. \n- Open Inventory" << endl;
           cin >> takeWeapon;
           cout << endl;
           if (takeWeapon == "Take" || takeWeapon == "take")
           {
            cout << "You take the weapon carefully still being cautious about your surroundings expecting a trap of some sort.\nYou now have the weapon in your hands and take a step back from the pedestal,\nnothing seems to happen" << endl;
            cout << endl;
            cout << "It was too soon for you to relax! The entrance to the room shuts closed in an instant! \nYou seem to now be trapped in the room \nYou start to panic. You start to use the weapon that you have just picked up without knowing what it would do and \nstart swinging at the walls with it, its creates a huge dent in the wall with ease but not enough to get out.\nThe impact was strong enough to blow the torch out." << endl;
            cout << endl;
            cout << "The torch goes out, Its now complete darkness in this small room." << endl;
               cout << endl;
               cout << "You start to feel something dripping onto your shoulder, you can tell from the texture that it is not water.\n\nIts Oil!\n\nYou try to feel around the room again to see if you can find some type of escape\nbefore the room fills with oil.\nThe oil is rushing in quicker by the second,\nits still completely dark in the room you're able to find the gap that the oil is coming from. \nYou try to squeeze through the gap of the oil before the oil \ncompletely fills the room, suffocating you but your just not able to fit.\n\nYou have no other choice but to use the weapon that you have to try and make the hole wider, you've already seen the force of the weapon when you tried to escape before." << endl;
               
               Death://Loop Thingy
               cout << endl;
               string death;
               
               cout << "Do you ready your Swing or Accept your impending doom." << endl;
               cin >> death;//Input
               
               if (death == "Swing" || death == "swing")
               {
                   cout << endl;
                   cout << "You ready your swing, closing your eyes hoping for the best and for the fact that if you didnt you would get oil in them.\n\nYou swing.\n\nThe worst has happened. You never expected the fact that a spark could have been made from the collision of impact.\n\nIt has ignited the oil, burning you to a crisp." << endl;
                   cout << "GAME OVER" << endl;
                   return 0;//End Code
               }
               else if (death == "Accept" || death == "accept")
               {
                   cout << endl;
                   cout << "You close your eyes accepting your fate as the room fills with oil.\nAll you can hear is the sound of the oil rushing in at a quicker pace that before.\n\nThe oil has almost completely filled up the room.\n\nYou end up getting suffocated by the oil, gasping for air." << endl;
                   cout << "GAME OVER" << endl;
                   return 0;//End Code
               }
               else
               {
                   cout << endl;
                   cout << "*Invalid input! Must answer with Swing or Accept*" << endl;
                   death.clear();
                   cout << endl;
                   goto Death;
               }
           }
           else if (takeWeapon == "Leave" || takeWeapon == "leave")
           {
               cout << "You successfully manage to find the exit of the cave and get out.\nBut you cant help but wonder what that weapon was and the power that it would have held." << endl;
          //Might make it so something else gets found instead
               cout << endl;
           }
           else if (Cave == "Inventory" || Cave == "inventory" || Cave == "Open" || Cave == "open")
            {
                system("clear");
                inventory();
            }
           else
           {
               cout << "*Invalid input! Must answer with Take, Leave or Open*" << endl;
               takeWeapon.clear();//Clear Variable
               goto TakeWeapon;//Loop back
               cout << endl;
           }
           
       }
       else if (caveStay == "No" || caveStay == "no" || caveStay == "n" || caveStay == "N")
           {
           // continues the rest of the code and exists the if statement
       }
       else 
       {
           cout << endl;
           cout << "*Invalid Input! Must answer with Yes or No*" << endl;
           caveStay.clear(); //clears variable
           cout << endl;
           goto CaveStay; //loops back
       }
       
   }
    else if (Cave == "leave" || Cave == "Leave")
    {
         
    }
    else if (Cave == "Inventory" || Cave == "inventory" || Cave == "Open" || Cave == "open")
    {
        system("clear");
        inventory();
        goto cave;
    }
    else 
    {
        cout << endl;
        cout << "*Invalid Input! Must answer with Stay, Leave or Open*" << endl; //Error
        cout << endl;
        Cave.clear(); //Clearing Variable
        goto cave; //Loop
    }
    
    cout << endl;   //New Line and continues code
        cout << "You stumble out of the cave to see if you can find some clue on where exactly you would be, each step is a struggle. \nIt feels like gravity is sucking you in." << endl;
        cout << "You take a look around at the enterance of the cave and are unable to recognise anything of your surroundings but you do seem to find a bag of some sorts." << endl;
        cout << "You check the contents of the bag." << endl;
        cout << endl;
        cout << "You find a Map" << endl;
        cout << endl;
        cout << "Some Potions" << endl;
        cout << endl;
        
        ifstream  stream1("classChoice.txt"); //Locates File
    string line ;

    while( std::getline( stream1, line ) )
    {
        if(line.find("Mage") != string::npos) // Will search for Mage in file
        { 
            cout << "And a Wand" << endl; //Print Line that is read in file.
            cout << endl;
            Bag:
            cout << "Do you wish to take the bag? (Y/N)" << endl;
            string bag;
            cin >> bag;
            cout << endl;
            if (bag == "Y" || bag == "y")
            {
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Map\n";
              myfile << "Potions x2\n";
              myfile << "Wand\n";
              myfile.close();
                cout << "Items Taken!" << endl;
                cout << endl;
            }
            else if (bag == "N" || bag == "n")
            {
                cout << "You leave the items behind, and are about to leave the area completely unarmed without knowing what could happen." << endl;
                cout << endl;
                Bag1:
                cout << "On second thought you think you might need at least a weapon\nDo you Take the Weapon Only? (Y/N)" << endl;
                string bag1;
                cout << endl;
                cin >> bag1;
                cout << endl;
                if (bag1 == "Y" || bag1 == "y")
                {
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Wand\n";
              myfile.close();
                    cout << "You take the Wand only from the bag." << endl;
                }
                else if (bag1 == "N" | bag1 == "n")
                {
                    cout << "You consider that the items in this bag might belong to someone else and leave everything behind." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Invalid Input! Must be a Y or an N!" << endl;
                    cout << endl;
                    bag1.clear();
                        goto Bag1;
                }
            }
            else 
            {
                cout << "Invalid Input! Must be an Y or an N!" << endl;
                bag.clear();
                goto Bag;
            }
        }
        else if (line.find("Priest") != string::npos)// Will search for Priest in file
        {
            cout << "And a Teared Talisman" << endl;
              cout << endl;
            Bag2:
            cout << "Do you wish to take the bag? (Y/N)" << endl;
            string bag;
            cin >> bag;
            cout << endl;
            if (bag == "Y" || bag == "y")
            {
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Map\n";
              myfile << "Potions x2\n";
              myfile << "Teared Talisman\n";
              myfile.close();
                cout << "Items Taken!" << endl;
            }         
            else if (bag == "N" || bag == "n")
            {
                cout << "You leave the items behind, and are about to leave the area completely unarmed without knowing what could happen." << endl;
                cout << endl;
                Bag3:
                cout << "On second thought you think you might need at least a weapon\nDo you Take the Weapon Only? (Y/N)" << endl;
                string bag1;
                cout << endl;
                cin >> bag1;
                cout << endl;
                if (bag1 == "Y" || bag1 == "y")
                {
                     ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Teared Talisman\n";
              myfile.close();
                    cout << "You take the Teared Talisman only from the bag." << endl;
                }
                else if (bag1 == "N" | bag1 == "n")
                {
                    cout << "You consider that the items in this bag might belong to someone else and leave everything behind." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Invalid Input! Must be a Y or an N!" << endl;
                    cout << endl;
                    bag1.clear();
                        goto Bag3;
                }
            }
            else 
            {
                cout << "Invalid Input! Must be an Y or an N!" << endl;
                bag.clear();
                goto Bag2;
            }
        }
        else if (line.find("Necromancer") != string::npos)// Will search for Necromancer in file
        {
            cout << "And a Feeble Staff" << endl;  
            Bag4:
            cout << endl;
            cout << "Do you wish to take the bag? (Y/N)" << endl;
            
            string bag;
            cin >> bag;
            cout << endl;
            if (bag == "Y" || bag == "y")
            {
                cout << endl;
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Map\n";
              myfile << "Potions x2\n";
              myfile << "Feeble Staff\n";
              myfile.close();
                cout << "Items Taken!" << endl;
            }
             else if (bag == "N" || bag == "n")
            {
                cout << "You leave the items behind, and are about to leave the area completely unarmed without knowing what could happen." << endl;
                cout << endl;
                Bag5:
                cout << "On second thought you think you might need at least a weapon\nDo you Take the Weapon Only? (Y/N)" << endl;
                string bag1;
                cout << endl;
                cin >> bag1;
                cout << endl;
                if (bag1 == "Y" || bag1 == "y")
                {
                     ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Feeble Staff\n";
              myfile.close();
                    cout << "You take the Feeble Staff only from the bag." << endl;
                }
                else if (bag1 == "N" | bag1 == "n")
                {
                    cout << "You consider that the items in this bag might belong to someone else and leave everything behind." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Invalid Input! Must be a Y or an N!" << endl;
                    cout << endl;
                    bag1.clear();
                        goto Bag5;
                }
            }
            else 
            {
                cout << "Invalid Input! Must be an Y or an N!" << endl;
                bag.clear();
                goto Bag4;
            }
        }
        else if (line.find("Warrior") != string::npos)// Will search for Warrior in file
        {
            cout << "And a Blunt Axe" << endl;
            Bag6:
              cout << endl;
            cout << "Do you wish to take the bag? (Y/N)" << endl;
            string bag;
            cout << endl;
            cin >> bag;
            cout << endl;
            if (bag == "Y" || bag == "y")
            {
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Map\n";
              myfile << "Potions x2\n";
              myfile << "Blunt Axe\n";
              myfile.close();
                cout << endl;
                cout << "Items Taken!" << endl;
            }
             else if (bag == "N" || bag == "n")
            {
                cout << "You leave the items behind, and are about to leave the area completely unarmed without knowing what could happen." << endl;
                cout << endl;
                Bag7:
                cout << "On second thought you think you might need at least a weapon\nDo you Take the Weapon Only? (Y/N)" << endl;
                string bag1;
                cout << endl;
                cin >> bag1;
                cout << endl;
                if (bag1 == "Y" || bag1 == "y")
                {
                     ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Blunt Axe\n";
              myfile.close();
                    cout << "You take the Blunt Axe only from the bag." << endl;
                }
                else if (bag1 == "N" | bag1 == "n")
                {
                    cout << "You consider that the items in this bag might belong to someone else and leave everything behind." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Invalid Input! Must be a Y or an N!" << endl;
                    cout << endl;
                    bag1.clear();
                        goto Bag7;
                }
            }
            else 
            {
                cout << "Invalid Input! Must be an Y or an N!" << endl;
                cout << endl;
                bag.clear();
                goto Bag6;
            }
        }
        else if (line.find("Hunter") != string::npos)// Will search for Hunter in file
        {
            cout << "And a Crusty CrossBow" << endl;
              cout << endl;
            Bag8:
            cout << "Do you wish to take the bag? (Y/N)" << endl;
            string bag;
            cout << endl;
            cin >> bag;
            cout << endl;
            if (bag == "Y" || bag == "y")
            {
                    ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Map\n";
              myfile << "Potions x2\n";
              myfile << "Crusty Crossbow\n";
              myfile.close();
                cout << endl;
                cout << "Items Taken!" << endl;
                cout << endl;
            }
            else if (bag == "N" || bag == "n")
            {
                cout << "You leave the items behind, and are about to leave the area completely unarmed without knowing what could happen." << endl;
                cout << endl;
                Bag9:
                cout << "On second thought you think you might need at least a weapon\nDo you Take the Weapon Only? (Y/N)" << endl;
                string bag1;
                cout << endl;
                cin >> bag1;
                cout << endl;
                if (bag1 == "Y" || bag1 == "y")
                {
                     ofstream myfile; //Creates txt doc of class chosen
              myfile.open ("Items.txt");
              myfile << "Crusty Crossbow\n";
              myfile.close();
                    cout << "You take the Crusty Crossbow only from the bag." << endl;
                }
                else if (bag1 == "N" | bag1 == "n")
                {
                    cout << "You consider that the items in this bag might belong to someone else and leave everything behind." << endl;
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Invalid Input! Must be a Y or an N!" << endl;
                    cout << endl;
                    bag1.clear();
                        goto Bag9;
                }
            }
            else 
            {
                cout << "Invalid Input! Must be an Y or an N!" << endl;
                bag.clear();
                goto Bag8;
            }
        }
        
    }
    cout << endl;;
    
    cout << "You start to explore the forest around the surrounding area, you cant see anything but trees and shurb.\n" << endl;
    //sleep()
    cout << "You start to hear a something up ahead, it sounds close to a person!" << endl;
    //sleep()
    cout << "Maybe they can tell you where you would be and even if your lucky can tell you how you even got here!" << endl;
    sleep (2);
    
    cout << endl;
    
    
    
    cout << "You Manage to Defeat the enemy and see the aura that was shrouding them disappear and fly away in the distance." << endl;
    //sleep()
    cout << "You decide to search the persons body for anything \nYou find a not on the body. It seems to be some type of coordinate." << endl;
    //sleep()
    cout << "Maybe this can can be some type of clue, but you have nothing else to go on." << endl;
    //sleep()
    cout << "You can only hope this location would be the place youll be able to find the answers you need..." << endl;
    sleep(3);
    finish();
    
        return 0;
}
