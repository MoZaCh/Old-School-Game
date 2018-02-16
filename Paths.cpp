#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;


int main()
{
    
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
        cout << "Must be a Y/N answer!" << endl; //Error Check
        // sleep
        cout << endl; //New Line
        goto confirmCheck; // Loops Back
    }
    
    // sleep
    
    cout << "You try to concentrate your thoughts, \nJust trying to gather your thoughts is causing your head to pound." << endl;
    // sleep
    
    cout << "You're able to just about remember small things of your past, your remember that you are a... *CLASS PICKED*" << endl;
    cout << endl;
    // sleep
    //Link To Classes 
    cout << "You seem to see to be near the enterance of the cave" << endl;
    
    cout << "Do you explore the rest of the cave or leave the cave to try and find your way back home." << endl;
    
    string Cave;
    
    cave: //Loop Thing
    
    cout << "1. Stay in the Cave. \n2. Leave the Cave." << endl;
    cout << endl;
    
    cout << "- Stay. \n- Leave." << endl;
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
       
       if(caveStay == "Yes" || caveStay == "yes") //confirming answer
       {
           cout << endl;
           cout << "You keep going, you keep taking a step further into the darkness.\nAt this point you are completely shrouded in darkness, you aren't able to see a single thing.\nYou aren't able to see anything, But you continue to venture onward, you end up hitting a wall.\nYou're able to feel a breeze on the other side and are even able to see a crack of light behind the rocks." << endl;
           cout << "You try to chip away at the rocks, finding it with ease like these rocks have been moved a lot.\nyou discover something hidden behind them, it seems to be some type of small room, lit up by just one torch.\nthere is a pedestal, there seems to be a weapon ontop, \nits a *DEPENDS ON CLASS*" << endl;
           return 0; //End Code
       }
       else if (caveStay == "No" || caveStay == "no")
       {
           // continues the rest of the code and exists the if statement
       }
       else 
       {
           cout << endl;
           cout << "not a valid option" << endl;
           caveStay.clear(); //clears variable
           cout << endl;
           goto CaveStay; //loops bacl
       }
       
   }
    else if (Cave == "leave" || Cave == "Leave")
    {
         cout << endl;   //New Line and continues code
    }
    
    else 
    {
        cout << endl;
        cout << "not a valid option" << endl; //Error
        cout << endl;
        Cave.clear(); //Clearing Variable
        goto cave; //Loop
    }
    
    cout << "Test" << endl; // TEST!
    
        return 0;
}
    
    
