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
    attack = 70;
    defend = 30;
    healthpoints = 20;
    }
    void SpellBook(){}
    void Staff(){}
    void Blink(){}
    void CastSpell(){}
    void FIREBALL(){}
    void LIGHTNING(){}
    void FREEZE(){}
    void TORNADO(){}
    
    
};    

class Priest : public Character
{
public :
    void abilities()
    {
    attack = 50;
    defend = 50;
    healthpoints = 50;
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
    attack = 80;
    defend = 50;
    healthpoints = 60;
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
    attack = 100;
    defend = 80;
    healthpoints = 70;
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
    attack = 100;
    defend = 100;
    healthpoints = 100;
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

