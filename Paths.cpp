#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;


int main()
{
    
cout << "You awake in a Forest, covered in snow." << endl;
    
sleep(2);
    
cout << "You seem to not be able to remember much but you do gather your name." << endl;
 
    sleep(3);
    

    string name;
    
    string confirm;
    
    userName:
    
     cout << "Please enter your name: " << endl; //Asks user for what their name would be
        cin >> name;
    
    confirmCheck:
    
    cout << "Are you sure? Please enter y/n: " << endl; //Confirms if the user is sure
    cin >> confirm;
    
    
    if (confirm == "Y" || confirm == "y") //Game Continues
    {
        cout << endl;
        
        cout << "Your head is in a daze" << endl;
        sleep(1);
    }
    
    else if (confirm == "N" || confirm == "n") //Loops back to the name
    {
        name.clear();
        goto userName;
    }
    
    else 
    {
        cout << "Must be a Y/N answer!" << endl; //Error Check
        sleep(1);
        cout << endl;
        goto confirmCheck;
    }
    
    sleep(1);
    
    cout << "You try to concentrate your thoughts, \nJust trying to gather your thoughts is causing your head to pound." << endl;
    sleep(3);
    
    cout << "Your able to just about remember small things of your past, your remember that you are a..." << endl;
    sleep(2);
    //Link To Classes 
    
    
    //Unfinished
    
    cout << "Test" << endl; // TEST!
    
        return 0;
}
    
    
