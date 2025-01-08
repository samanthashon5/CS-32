// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

// You may add data members and other member functions to this class.
const int ROWS = 18;
const int COLS = 70;

class Game {
public:
  Game(int goblinSmellDistance);
  void play();
  void draw();

private:
  char grid[18][70];
  int m_distance;
};

class Temple {
public:
  Temple();
  ~Temple();
  void display();

  // each maze is 18 rows high and 70 columns wide

  // each level has outer edges surrounded by walls

  // level 5 has no stairway down

  // start on new level L
  // M monsters where M=randInt(2,5*(L+1)+1)

  // 4 random rooms
  // 3 corridors
private:
  int cols;
  int rows;
};

#endif // GAME_INCLUDED
