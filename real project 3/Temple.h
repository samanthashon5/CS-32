#ifndef TEMPLE_H
#define TEMPLE_H
#include "Actor.h"
#include "GameObject.h"
class Player;
class Snakewomen;
class Bogeymen;
class Dragons;
class Goblins;

class Temple
{
public:
 Temple();
 ~Temple();

//get level
int getLevel();

//set level
void setLevel(int l);

//draw the temple
 void draw();
 bool isWall(int r, int c) const;
 bool isMonster(int r, int c) const;
 bool isPlayer(int r, int c) const;

//add player to temple
void addPlayer();
Player* player() const;

//add Monsters to temple
void addSnakewomen();
Snakewomen* snakewomen() const;

void addBogeymen();
Bogeymen* bogeymen() const;

void addDragon();
Dragons* dragon() const;

void addGoblin();
Goblins* goblin() const;

// //add GameObjects
// void addGameObject(GameObjects* g);

//while player moves, change grid
void changeGrid(int r, int c, char ch);

//access player position
int getProw();
int getPcol();
Player* getPlayer();

// //access monster
Snakewomen* getSnake();
Bogeymen* getBogey();
Dragons* getDragon();
Goblins* getGoblin();

//update temple when monsters move
void update();

// //set position of every object
// bool setPos(int r, int c);

private:
 int mlevel = 0;
 char grid[18][70];
 Player* mPlayer;
 Snakewomen* mSnake;
 Bogeymen* mBogey;
 Dragons* mDragon;
 Goblins* mGoblin;
};


#endif