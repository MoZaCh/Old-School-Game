#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;


int main()
{
    
cout << "You awake in a Forest, covered in snow." << endl;
    
// sleep
    
cout << "You seem to not be able to remember much but you do gather your name." << endl;
 
    // sleep
    

    string name; //Variable
    
    string confirm; //Variable
    
    userName: //Loop thingy
    
     cout << "Please enter your name: " << endl; //Asks user for what their name would be
        cin >> name; //Input
    
    confirmCheck: //Loop Thingy
    
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
    
    cout << "Your able to just about remember small things of your past, your remember that you are a..." << endl;
    // sleep
    //Link To Classes 
    cout << "You seem to see to be near the enterance of the cave" << endl;
    
    cout << "Do you explore the rest of the cave or leave the cave to try and find your way back home." << endl;
    
    string Cave;
    
    cave: //Loop Thing
    
    cout << "1. Stay in the Cave. \n2. Leave the Cave." << endl;
    cout << endl;
    
    cout << "Stay. \nLeave." << endl;
    cin >> Cave;
        
   if (Cave == "stay" || Cave == "Stay")
   {
       cout << endl;
       cout << "cave" << endl; //Stuff about cave
       
       return 0; //End Code
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
    
    //UNFINISHED
    
    cout << "Test" << endl; // TEST!
    
        return 0;
}
    
    
