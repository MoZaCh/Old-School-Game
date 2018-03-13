# D5-Something - RPG Game

------------------------------

# REMEMBER TO MAKE SURE THE FILES ARE NAMED THE SAME AS IN THE CODE
---------------

# Files Needed To Run

Paths.cpp

Finish.cpp

Inventory.cpp

Combat.cpp

MergedClasses.cpp

EnemyClasses.cpp

sqlcon.cpp

libsqlite.hpp

testdb.db

NCMenu.cpp

Credits.cpp

-------------------------------------


To Install ncurses: (Needed For Main Menu)
------
sudo apt-get install libncurses-dev

And to compile ncurse code write -lncurses in compile code, E.g:

g++ stuff -o stuff -lncurses


-------------------

To Install SQL Package
---
sudo apt-get install libsqlite3-dev

----
C++14 Package
--

sudo add-apt-repository ppa:ubuntu-toolchain-r/test

sudo apt-get update

sudo apt-get install g++-4.9

also make your g++ 4.9 as a default compiler with this command:

sudo ln -f -s /usr/bin/g++-4.9 /usr/bin/g++ 

----

Classes
--------

Include all classes have different attack, defend, health points and more.

Classes:

-------------------------

*Mage 
-
Attack - (HIGH)

Defence - (LOW)

HealthPoints(HP) - (LOW)

MANA

-Staff/SpellBook

-Blink

-Cast Spell


-FIREBALL

-LIGHTNING

-FREEZE

-TORNADO

------------------------

*Priest 
-
Attack - (LOW)

Defence - (MEDIUM)

HealthPoints(HP) - (MEDIUM)

MANA

-Talisman

-Levitate

-Heal

-Spell

----------------------------

*Warrior 
-
Attack - (MEDIUM)

Defence - (HIGH)

HealthPoints(HP) - (HIGH)


-Axe/GreatSword

-Swing

-Block


-Guard (TEMP)

-Charge

-Stun

-Blade Storm

--------------------------

*Necromancer 
-
Attack - (LOW)

Defence - (MEDIUM)

HealthPoints(HP) - (HIGH)

USES HEALTH



-Staff

-Summon

-Cast Spell


-Summon Ghoul

-Life Drain

-Corrupt

-Fear

-Burn

-Buffed from self damage-

-------------

*Hunter
-
Attack - (MEDIUM)

Defence - (LOW)

HealthPoints(HP) - (MEDIUM)

-SPECIAL AMMO?



-Bow

-Dagger

-Shoot

-Climb


-Snipe

-Call

-Assassinate

-Rain of Arrors

-Throw Dagger

-Set Traps




-----------------------------------------------------------------------------------------
Story
-----

Games Starts.

Choose Name.

Choose Class.

Throw Player in to the Game, Literally...

Percentage chance for success?

-----------------------------------------------------------------------------------------

Main Menu
---------

Title

Start New  Game

Load

Quit

------------------------------------------------------------------------------------------

Combat
-----
Percentage Chance for most things

*Chance of success*

attack

defence

ability


*Status Effects?*


*Changes Needed to be Made
__________________________

Stop mana from being able to drop below 0 and stopping spells being used when not enough mana.

Include a ability which takes no mana and does physical damage instead of magic, like bash or swign for mage.

Other abilities and spells for other classes (Will Be changed depending on how the story would be and items they have)

Have it access the inventory so able to use items such as potions and see what weapon the user has (Waiting for harsh)

Maybe have some way that after each round in combat, user regenerates mana and health (Not Important can be done after)

-----------------------------------------------------------------------------------------------

Inventory
---------
Menu to open inventory

Options to close inventory

Displays Items that use would have picked up (links to Paths.cpp Code)

Navigation? (Next Page and such)

*List items inventory

Item counter

-------------------------------------------------------------------------------------------------
