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
    void SpellBook();
};    

class Priest : public Character
{
public :
    void Talisman(); 
};
class Warrior : public Character
{
public :
    void GreatSword();
      
};
class  Necromancer : public Character
{
public :
    void Staff ();
     
};
class  Hunter : public Character
{
public :
    void Bow ();  
};


int main()
{
    
  Character C1;
  C1.message();
  Necromancer N1;
  N1.Staff();
  return 0;
}
