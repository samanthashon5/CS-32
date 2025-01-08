#include "Temple.h"
#include "utilities.h"
#include <iostream>
#include <set>
using namespace std;

Temple::Temple() //: mPlayer(new Player(this, randInt(1,16), randInt(1,68), 100, "short sword", 0, 0, 0))
{
  // draw borders
  int r, c;

  for (r = 0; r < 18; r++) {
    grid[r][0] = '#';
    grid[r][69] = '#';
  }

  for (c = 0; c < 70; c++) {
    grid[0][c] = '#';
    grid[17][c] = '#';
  }

  for(int i = 1; i < 17; i++)
    for(int j = 1; j < 69; j++)
      {
        grid[i][j] = ' ';
      }
  
  //add player
  addPlayer();

  //add monsters
  addSnakewomen();
  addBogeymen();
  addDragon();
}

//destroy temple
Temple::~Temple()
{
}

//level
int Temple::getLevel()
{
  return mlevel;
}

void Temple::setLevel(int l)
{
  mlevel = l;
}

//impenetrable characters
bool Temple::isWall(int r, int c) const 
{
  return grid[r][c] == '#';
}
bool Temple::isMonster(int r, int c) const
{
  if(grid[r][c] == 'S' || grid[r][c] == 'D' || grid[r][c] == 'B' || grid[r][c] == 'G')
  {
    return true;
  }
  return false;
}
bool Temple::isPlayer(int r, int c) const
{
  return grid[r][c] == '@';
}
  
void Temple::changeGrid(int r, int c, char ch)
{
  grid[r][c] = ch;
}

//player position
int Temple::getPcol()
{
  return mPlayer -> col();
}

int Temple::getProw()
{
  return mPlayer -> row();
}

Player* Temple::getPlayer()
{
  return mPlayer;
}

//adding actors
void Temple::addPlayer()
{
  // Weapons* shortsword = new ShortSwords("short sword", 0, 2)
  mPlayer = new Player(this, randInt(1,16), randInt(1,68), 20, "short sword", 2, 2, 0, 2);
}

//adding monsters
void Temple::addSnakewomen()
{
  // Weapons* magicfangs = new MagicFangs("magic fangs of sleep", 3, 2);
  mSnake = new Snakewomen(this, randInt(1,16), randInt(1,68), randInt(3,6), "magic fangs", 3, 3, 0, 2);
}

Snakewomen* Temple::getSnake()
{
  return mSnake;
}

void Temple::addBogeymen()
{
  // Weapons* shortsword = new ShortSwords("short sword", 0, 2);
  mBogey = new Bogeymen(this, randInt(1,16), randInt(1,68), randInt(5,10),"short sword", 2, randInt(2,3), 0, randInt(2,3));
}

Bogeymen* Temple::getBogey()
{
  return mBogey;
}

void Temple::addDragon()
{
  // Weapons* longswords = LongSwords("long sword", 2, 4)
  mDragon = new Dragons(this, randInt(1,16), randInt(1,68), randInt(20,25), "long sword", 4, 4, 0, 4);
}

Dragons* Temple::getDragon()
{
  return mDragon;
}

void Temple::addGoblin()
{
  mGoblin = new Goblins(this, randInt(1,16), randInt(1,68), randInt(15,20), "short sword", 1, 1, 0, 3);
}

Goblins* Temple::getGoblin()
{
  return mGoblin;
}

// //adding weapons
// void Temple::add

//draw temple
void Temple::draw() {
    clearScreen();
    for (int i = 0; i < 18; i++) 
    {
        for (int j = 0; j < 70; j++) 
        {
            if (i == mPlayer->row() && j == mPlayer->col())
            {
              cout << '@';
            }
            else if (i == mSnake->row() && j == mSnake->col())
            {
              cout << 'S';
            }
            else if (i == mBogey->row() && j == mBogey->col())
            {
              cout << 'B';
            }
            else if (i == mDragon->row() && j == mDragon->col())
            {
              cout << 'D';
            }
            else
            {
              cout << grid[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;

  cout << "Level: " << getLevel() << ", Hit points: " << mPlayer -> hit() << ", Armor: " << mPlayer -> armor() << ", Strength: " << mPlayer -> strength() << ", Dexterity: " << mPlayer -> dex() << endl;
}

void Temple::update() 
{
  
  grid[mSnake->row()][mSnake->col()] = ' '; // Clear the old position
  mSnake -> move(3); // Move the snakewoman
  grid[mSnake->row()][mSnake->col()] = 'S'; // Set the new position

  grid[mBogey -> row()][mBogey -> col()] = ' '; // Clear the old position
  mBogey -> move(5); // Move the bogeymen
  grid[mBogey -> row()][mBogey -> col()] = 'B';

  grid[mGoblin -> row()][mGoblin -> col()] = ' '; // Clear the old position
  mGoblin -> move(15); // Move the goblin
  grid[mGoblin -> row()][mGoblin -> col()] = 'G';
  
}
