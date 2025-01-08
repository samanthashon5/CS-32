#ifndef Game_h
#define Game_h
#include "City.h"

int decodeDirection(char dir);
class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nTooters);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
};

#endif