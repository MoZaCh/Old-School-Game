#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;


int path()
{
    
cout << "You awake in a Cave, covered in gravel and dirt." << endl;
    
sleep(1);
    
cout << "You seem to not be able to remember much but you do gather your name." << endl;
 
    sleep(2);
    

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
        sleep(1);
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
        sleep(2);
        cout << endl; //New Line
        goto confirmCheck; // Loops Back
    }
    
    sleep(1);
    
    cout << "You try to concentrate your thoughts, \nJust trying to gather your thoughts is causing your head to pound." << endl;
    sleep(3);
    
    cout << "You're able to just about remember small things of your past, your remember that you are a... *CLASS PICKED*" << endl;
    sleep(3);
    
    cout << endl;
    
    
    //Link To Classes 
    cout << "You seem to see to be near the enterance of the cave" << endl;\
        
        sleep(2);
    
    cout << "Do you explore the rest of the cave or leave the cave to try and find your way back home." << endl;
    sleep(2);
    
    string Cave;
    
    cave: //Loop Thing
    
    cout << "Stay in the Cave. \nLeave the Cave." << endl;
    cout << endl;
    
    cout << "- Stay. \n- Leave." << endl;
    cin >> Cave;
        
   if (Cave == "stay" || Cave == "Stay")
   {
       cout << endl;
       cout << "You decide to stay in the cave to explore, maybe you'll be able to find some answer for why\nyou are in this cave and how you got here." << endl; //Stuff about cave
       sleep(4);
       
       cout << "As you venture through the cave you are finding it more difficult to see with each step" << endl;
       sleep(3);
       
       string caveStay;
       
       CaveStay: //Loop thingy
       
       cout << "Do you press on?\n\nYes.\nNo." << endl; 
       cin >> caveStay;
       
       if(caveStay == "Yes" || caveStay == "yes") //confirming answer
       {
           cout << endl;
           cout << "You keep going, you keep taking a step further into the darkness.\nAt this point you are completely shrouded in darkness, you aren't able to see a single thing,\nBut you continue to venture onward, you end up hitting a wall.\nYou're able to feel a breeze on the other side and are even able to see a crack of light behind the rocks." << endl;
           sleep(8);
           cout << endl;
           cout << "You try to chip away at the rocks, finding it with ease like these rocks have been moved a lot.\nyou discover something hidden behind them, it seems to be some type of small room, lit up by just one torch.\nthere is a pedestal, there seems to be a weapon ontop, \nits a *DEPENDS ON CLASS*" << endl;
           sleep(7);
           cout << endl;
           cout << "You inspect the pedestal, you don't see anything strange about the pedestal other than it has some ancient hieroglyphics \non it which you arent able to read." << endl;
           sleep(6);
           cout << endl;
           cout << "Do you wish to take the weapon?" << endl;
           
           
           TakeWeapon://Loop Thingy
           
           cout << endl;
           
           string takeWeapon;
           cout << "Take the weapon and dive into possible dangers.\nLeave it alone and find the exit." << endl;
           cin >> takeWeapon;
           cout << endl;
           if (takeWeapon == "Take" || takeWeapon == "take")
           {
            cout << "You take the weapon carefully still being cautious about your surroundings expecting a trap of some sort.\nYou now have the weapon in your hands and take a step back from the pedestal,\nnothing seems to happen" << endl;
            sleep(6);
            cout << endl;
            cout << "It was too soon for you to relax for the entrance to the room shuts closed. you seem to now be trapped in the room." << endl;
            sleep(3);
               cout << "You start to panic." << endl;
            sleep(2);
               cout << "You start to use the weapon that you have just picked up without knowing what it would do and start swinging at the walls with it." << endl;
            sleep(3);
               cout << "Its creates a huge dent in the wall with ease but not enough to get out." << endl;
            sleep(3);
               cout << "The impact was strong enough to blow the torch out." << endl;
            sleep(2);
            cout << endl;
            cout << "The torch goes out, Its now complete darkness in this small room." << endl;
              sleep(3);
               cout << endl;
               cout << "You start to feel something dripping onto your shoulder, you can tell from the texture that it is not water.\n" << endl;
               sleep(4);
               cout << "Its Oil!\n" << endl;
               sleep(2);
               cout << "You try to feel around the room again to see if you can find some type of escape before the room fills with oil." << endl;
               sleep(3);
               cout << "The oil is rushing in quicker by the second, its still completely dark in the room you're able to find the gap that the oil is \ncoming from." << endl; 
               sleep(3);
               cout << "You try to squeeze through the gap of the oil before the oil completely fills the room, suffocating you but your just not able to fit.\n" << endl;
               sleep(3);
               cout << "You have no other choice but to use the weapon that you have to try and make the hole wider, you've already seen the force of the weapon when you tried to escape before." << endl;
               sleep(5);
               
               Death://Loop Thingy
               cout << endl;
               string death;
               
               cout << "Do you ready or Swing or Accept your impending doom." << endl;
               cin >> death;//Input
               
               if (death == "Swing" || death == "swing")
               {
                   cout << endl;
                   cout << "You ready your swing, closing your eyes hoping for the best and for the fact that if you didnt you would get oil in them.\n" <<endl; 
                   sleep(3);
                   cout << "You swing.\n" << endl; 
                   sleep(2);
                   cout << "The worst has happened." << endl;
                   sleep(2);
                   cout << "You never expected the fact that a spark could have been made from the collision of impact.\n" << endl;
                   sleep(3);
                   cout << "It has ignited the oil, burning you to a crisp." << endl;
                  sleep(2); 
                   cout << "GAME OVER" << endl;
                   return 0;//End Code
               }
               else if (death == "Accept" || death == "accept")
               {
                   cout << endl;
                   cout << "You close your eyes accepting your fate as the room fills with oil." << endl;
                   sleep(2);
                   cout << "All you can hear is the sound of the oil rushing in at a quicker pace that before.\n" << endl;
                   sleep(2);
                   cout << "The oil has almost completely filled up the room.\n" << endl;
                   sleep(2);
                   cout << "You end up getting suffocated by the oil, gasping for air." << endl;
                   sleep(2);
                   cout << "GAME OVER" << endl;
                   return 0;//End Code
               }
               else{
                   cout << endl;
                   cout << "*Invalid input! Must answer with Swing or Accept*" << endl;
                   death.clear();
                   sleep(2);
                   cout << endl;
                   goto Death;
               }
           }
           else if (takeWeapon == "Leave" || takeWeapon == "leave")
           {
               cout << "You successfully manage to find the exit of the cave and get out." << endl;
               sleep(1);
               cout << "But you cant help but wonder what that weapon was and the power that it would have held." << endl;
               sleep(3);
               cout << endl;
           }
           else
           {
               cout << "*Invalid input! Must answer with Take or Leave*" << endl;
               takeWeapon.clear();//Clear Variable
               sleep(2);
               goto TakeWeapon;//Loop back     
           }
           
       }
       else if (caveStay == "No" || caveStay == "no")
           {
           // continues the rest of the code and exists the if statement
       }
       else 
       {
           cout << endl;
           cout << "*Invalid Input! Must answer with Yes or No*" << endl;
           caveStay.clear(); //clears variable
           sleep(2);
           cout << endl;
           goto CaveStay; //loops back
       }
       
   }
    else if (Cave == "leave" || Cave == "Leave")
    {
         cout << endl;   //New Line and continues code
    }
    
    else 
    {
        cout << endl;
        cout << "*Invalid Input! Must answer with Stay or Leave*" << endl; //Error
        cout << endl;
        Cave.clear(); //Clearing Variable
        sleep(2);
        goto cave; //Loop
    }
    
    
    
    
    cout << endl;
    cout << "Test" << endl; // TEST!
    
        return 0;
}
    
    
