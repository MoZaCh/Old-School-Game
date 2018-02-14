# include <iostream>
using namespace std;
class Character
{
  public :
    void message()
    {
    string choice;
    cout << "Please choose a character"<<endl;
    cin >> choice ;  
    }
  protected :
    int attack;
    int defend;
    int healthpoints;
};
class Mage : public Character
{
public :
    void weapon()
    
    {
    cout<<"Staff/SpellBook"<<endl; 
    }

};
class Priest : public Character
{
public :
    void weapon1() 
     
    {
      cout<<"Talisman"<<endl;
    } 
};
class Warrior : public Character
{
public :
    void weapon2()
     
    {
      cout<<"Axe/GreatSword"<<endl;
    }  
};
class  Necromancer : public Character
{
public :
    void weapon3 ()
     
    {
     cout<<"Staff"<<endl; 
    }  
};
class  Hunter : public Character
{
public :
    void weapon4 ()
     
    {
     cout<<"Bow"<<endl;
    }  
};


int main()
{
    
  Character C1;
  C1.message();
  Necromancer N1;
  N1.weapon3();
  return 0;
}
