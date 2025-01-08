#include "Actor.h"
#include "utilities.h"
#include <iostream>
using namespace std;

// Actor implementations
Actor::Actor(Temple *t, int r, int c, int hit, std::string weapon, int armor,
             int dex, int sleep, int strength)
    : mtemple(t), mrow(r), mcol(c), mhit(hit), mweapon(weapon), marmor(armor),
      mdex(dex), msleep(sleep), mstrength(strength) {}

//accessors
int Actor::row() { return mrow; }
int Actor::col() { return mcol; }
int Actor::hit() { return mhit; }
int Actor::armor() { return marmor; }
int Actor::dex() { return mdex; }
int Actor::sleep() { return msleep; }
int Actor::strength() { return mstrength; }
string Actor::weapon() { return mweapon; }
Temple *Actor::temple() { return mtemple; }
// Weapons* Actor::getWeapon() const { return mweapon; }

//mutators
void Actor::setrow(int r) { mrow = r; }
void Actor::setcol(int c) { mcol = c; }
void Actor::sethit(int h) { mhit = h; }
void Actor::setstrength(int s) { mstrength = s; }
// void Actor::setWeapon(Weapons* weapon) { mweapon = weapon; }

// Player implementations
Player::Player(Temple *t, int r, int c, int hit, std::string weapon, int armor,
               int dex, int sleep, int strength)
    : Actor(t, r, c, 20, weapon, 2, 2, 0, 2) {}

bool Player::move(Direction dir) {
  switch(dir)
    {
      case UP:
        if(row() > 1)
        {
          if (!temple()->isWall(row() - 1, col()) || !temple()->isMonster(row() - 1, col())) 
          {
            temple() -> changeGrid(row(), col(), ' ');
            setrow(row() - 1);
            return true;
          }
        }
        break;
      case DOWN:
        if(row() < 15)
        {
          if (!temple()->isWall(row() + 1, col()) || !temple()->isMonster(row() + 1, col())) 
          {
            temple() -> changeGrid(row(), col(), ' ');
            setrow(row() + 1);
            return true;
          }
        }
        break;
      case LEFT:
        if(col() > 1)
        {
          if (!temple()->isWall(row(), col() - 1) || !temple()->isMonster(row(), col() - 1))
          {
            temple() -> changeGrid(row(), col(), ' ');
            setcol(col() - 1);
            return true;
          }
        }
        break;
      case RIGHT:
        if(col() < 69)
        {
          if(!temple()->isWall(row(), col() + 1) || !temple()->isMonster(row(), col() + 1)) 
          {
            temple() -> changeGrid(row(), col(), ' ');
            setcol(col() + 1);
            return true;
          }
        }
        break;
      case NONE:
      default:
        return false;
    }
  return false;
}

// //actions
// void Player::attack(Actors* m)
// {
//   if(m)
//   {
//     int damage = mweapon -> dam();
//     m -> sethit(m -> hit() - damage);
//     cout << "You attacked the " << m -> name() << " for " << damage << " damage." << endl;
//   }
  
// }

//cheat
void Player::cheat()
{
  sethit(50);
  setstrength(9);
}
// Monster implementations
Monsters::Monsters(Temple *t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength) : Actor(t, r, c, 0, weapon, 0, 0, 0, 0) //mdistance(distance)
{}

Monsters::~Monsters()
{}


void Monsters::move(int distance)
{
  if(distance >= (abs((temple() -> getProw()) - row())) + (abs((temple() -> getPcol()) - col())))
  {
    if(temple() -> getProw() > row())
    {
      if(!temple() -> isPlayer(row() + 1, col()))
      {
        setrow(row() + 1);
      }
      else
      {
        return;
      }
    }

    else if(temple() -> getProw() < row())
    {
      if(!temple() -> isPlayer(row() - 1, col()))
        {
          setrow(row() - 1);
        }
        else
        {
          return;
        }
    }

    else if(temple() -> getPcol() > col())
    {
      if(!temple() -> isPlayer(row(), col() + 1))
        {
          setcol(col() + 1);
        }
        else
        {
          return;
        }
    }

    else if(temple() -> getPcol() < col())
    {
      if(!temple() -> isPlayer(row(), col() - 1))
        {
          setcol(col() - 1);
        }
        else
        {
          return;
        }
    }
  }
  return;
}

Snakewomen::Snakewomen(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength) : Monsters(t, r, c, randInt(3,6), weapon, 3, 3, 0, 2)
{}

Snakewomen::~Snakewomen()
{}

Bogeymen::Bogeymen(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength) : Monsters(t, r, c, randInt(5,10), weapon, 2, randInt(2,3), 0, randInt(2,3))
{}

Bogeymen::~Bogeymen()
{}

Dragons::Dragons(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength) : Monsters(t, r, c, randInt(20,25), weapon, 4, 4, 0, 4)
{}

Dragons::~Dragons()
{}

Goblins::Goblins(Temple* t, int r, int c, int hit, std::string weapon, int armor, int dex, int sleep, int strength) : Monsters(t, r, c, randInt(15,20), weapon, 1, 1, 0, 3)
{}

Goblins::~Goblins()
{}

// //goblin recursive fuction
// virtual void Goblins::move(int distance)
// {
  
// }