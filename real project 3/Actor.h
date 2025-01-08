#ifndef ACTOR_H
#define ACTOR_H
#include "Temple.h"
#include "GameObject.h"
#include <string>

class Temple;

class Actor
{
public:
 Actor(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 // virtual ~Actor();
 // //position, hit points, weapon, armor points, strength points, dexterity points, sleep time
 // virtual void attack() = 0;

enum Direction
{
  NONE = 0,
  LEFT = 1,
  RIGHT = 2,
  UP = 3,
  DOWN = 4,
};

int row();
int col();
int hit();
std::string weapon();
int armor();
int dex();
int sleep();
int strength();
Temple* temple();
// Weapons* getWeapon() const;

void setrow(int r);
void setcol(int c);
void sethit(int h);
void setstrength(int s);
// void setWeapon(Weapons* weapon);

private:
Temple* mtemple;
// Weapons* mweapon;
int mrow;
int mcol;
int mhit;
std::string mweapon;
int marmor;
int mdex;
int msleep;
int mstrength;
};


class Player: public Actor
{
public:

//20 hit points(max), before each command 1-10 chance player regains a hit point
//can increase max hit point val by reading enhance health scroll
//weapon = short sword
//2 armor points (read scroll of enhance armor)
//2 strength points (read scroll of strength)
//2 dexterity points (read scroll of dexterity)
 Player(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 // virtual ~Player();


 //change current weapon with w command
 // void changew();

 //current weapon and items player picked up
 //when scroll picked up, self-destructs
 //pickup() only if inventory <= 25
 //type i
 // void inventory();

 //h.l.k.j or arrows
bool move(Direction dir);
bool canMove(Direction dir);


 // //move to monster next to player
 // virtual void attack(Actors* m);

 //stand on object and type g
 //check if inventory is full
 //pickup golden idol ->game over
// std::string pickup();

 //clear screen, display inventory and 
 //character read from keyboard(if letter of weapon, becomes current weapon, prev weapon in inventory)
 //if not, weapon doesn't change
 // //type w
 // void wield();

 //clear screen, display inventory, 
 //character read from keyboard(if letter of scroll, scroll performs magic and self destructs)
 //type r
 // void read();

 // //quit game
 // //type q
 // void quit();

 // //cheat 
 // //player strength 9, max hit points 50
 // //type c
 void cheat();

private:

};

class Monsters: public Actor
{
public:
 Monsters(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
// int distance);
 virtual ~Monsters();
 // void doNothing();
 virtual void move(int distance); //same for bogeymen, dragon, and snakewomen
 //can also attack
 //if monster next to player, it will attack
 //when monster die, may drop item if no item in position
//  int getDistance();
// //set diff smelling distances
//  void setDistance(int d);
private:
  // int mdistance;
};

class Bogeymen: public Monsters
{
public:
 //appear only on level 2 or deeper
 //hit points (random int 5-10)
 //weapon (short sword)
 //strength (random int 2-3)
 //dexterity (random int 2-3)
 //armor (2)
 Bogeymen(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 virtual ~Bogeymen();

 //1-5 steps away from player (ignore walls and other monsters)
 //move one step closer to row/column player is on
 //if too far, don't move

 //if dead, 1-10 chance of dropping magic axe if no item at position
};

class Snakewomen: public Monsters
{
public:
 //any temple level
 //hit points (random int 3-6)
 //weapon (magic fangs of sleep)
 //strength (2)
 //dexterity (3)
 //armor (3)
 Snakewomen(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 virtual ~Snakewomen();

 //1-3 steps away from player (ignore walls and other monsters)
 //move one step closer to row/column player is on
 //if too far, don't move
 // void smell();

 //if dead, 1-3 chance of dropping magic fangs of sleep if no item at position
};

class Dragons: public Monsters
{
public:
 //temple level 3 or deeper
 //hit points (random int 20-25)
 //weapon (long sword)
 //strength (4)
 //dexterity (4)
 //armor (4)
 Dragons(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 virtual ~Dragons();

 //will attack if player next to it

 //can regain hit points (1-10 chance of regaining 1 hit point to its initial max)

 //if dead,drops scroll if no item at position
};

class Goblins: public Monsters
{
public:
 //any temple level
 //hit points (random int 15-20)
 //weapon (short sword)
 //strength (3)
 //dexterity (1)
 //armor (1)
 Goblins(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength);
 virtual ~Goblins();

 //optimal move for goblin smell()
 //USE RECURSION
 // void optimal();
 //1-15 steps away from player (must be a path it can reach the player)
 //make optimal move
 //Note: program must use arguent passed to Game constructor as distance
 // void smell();

 // virtual void move(int distance);
 //if dead, 1 in 3 chance of dropping either magic axe or magic fangs of sleep if no item in position
};

#endif