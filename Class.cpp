# include <iostream>
using namespace std;
class Character
{
  public :
    void message()
    {
    string choice;
    cout << "Please choose a character"<<endl<<"Mage"<<endl<<"Priest"<<endl<<"Warrior"<<endl<<"Necromancer"<<endl<<"Hunter"<<endl;
    cin >> choice;  
    }
  protected :
    int attack;
    int defend;
    int healthpoints;
};
class Mage : public Character
{
 
public :
    
    void SpellBook(){}
    void Staff(){}
};    

class Priest : public Character
{
public :
    void Talisman(){} 
};
class Warrior : public Character
{
public :
    void GreatSword(){}
    void Axe(){}
    
      
};
class  Necromancer : public Character
{
public :
    void Staff (){}
     
};
class  Hunter : public Character
{
public :
    void Bow (){}
};


int main()
{
    
  Character C1;
  C1.message();
  return 0;
}
