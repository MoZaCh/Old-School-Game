# include <iostream>
using namespace std;
class Character
{
  public :
    void message()
    {
    string choice;
    cout << "Please choose a character"<<endl<<"1. Mage"<<endl<<"2. Priest"<<endl<<"3. Warrior"<<endl<<"4. Necromancer"<<endl<<"5. Hunter"<<endl;
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
    void abilities()
    {
    attack = 80;
    defend = 35;
    healthpoints = 50;
    }
    void SpellBook(){}
    void Staff(){}
    void Blink(){}
    void CastSpell(){}
    void Fireball(){}
    void Lighting(){}
    void Freeze(){}
    void Torando(){}
    
    
};    

class Priest : public Character
{
public :
    void abilities()
    {
    attack = 35;
    defend = 75;
    healthpoints = 75;
    }
    void Talisman(){}
    void Levitate(){}
    void Heal(){}
    void Spell (){}
    
};
class Warrior : public Character
{
public :
    void abilities()
    {
    attack = 75;
    defend = 100;
    healthpoints = 100;
    }
    void GreatSword(){}
    void Axe(){}
    void Stun(){}
    void Swing(){}
    void Block(){}
    void Guard(){}
    void Charge(){}
    void BladeStorm(){}
};

class  Necromancer : public Character
{
public :
    void abilities()
    {
    attack = 50;
    defend = 75;
    healthpoints = 100;
    }
    void Staff (){}
    void Summon (){}
    void CastSpell (){}
    void SummonGhoul (){}
    void LifeDrain (){}
    void Corrupt (){}
    void Fear (){}
    void Burn (){}
    void Buffedfromselfdamage (){}
     
};
class  Hunter : public Character
{
public :
void abilities()
    {
    attack = 75;
    defend = 20
    healthpoints = 50;
    }
    void Bow (){}
    void Dagger (){}
    void Shoot (){}
    void Climb (){}
    void Snipe (){}
    void Call (){}
    void Assassinate (){}
    void RainofArrors(){}
    void ThrowDagger (){}
    void SetTraps(){}
};


int main()
{
    
  Character C1;
  C1.message();
  return 0;
}

