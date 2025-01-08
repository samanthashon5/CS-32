// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Actor.h"
#include "Temple.h"

// You may add data members and other member functions to this class.
const int ROWS = 18;
const int COLS = 70;
class Player;
class Temple;


class Game {
public:
  Game(int goblinSmellDistance);
  ~Game();
  void play();
  // void draw();
  // bool addPlayer(int r, int c);
  // Player* player() const;
  // void changeGrid(int r, int c, char ch);
  // int getProw();
  // int getPcol();

private:
  Temple* temple;
  // Snakewomen* mSnake;
  //int m_distance = 0;
  //create list of monsters (add when generating level)
};


#endif // GAME_INCLUDED
