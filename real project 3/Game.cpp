// Game.cpp

#include "Game.h"
#include "utilities.h"
#include "Actor.h"
#include "Temple.h"
#include <iostream>
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance)
{

//  level
temple = new Temple();

}

//destroy game
Game::~Game()
{
  delete temple;
}

// You will presumably add to this project other .h/.cpp files for the various
// classes of objects you need to play the game:  player, monsters, weapons,
// etc.  You might have a separate .h/.cpp pair for each class (e.g., Player.h,
// Bogeyman.h, etc.), or you might put the class declarations for all actors in
// Actor.h, all game objects in GameObject.h, etc.

void Game::play() {
  temple -> draw();
  temple -> update();
  // cout << "The game hasn't been implemented yet." << endl;
  cout << "Press q to exit game." << endl;
  while (getCharacter() != 'q')
    {
      char input = getCharacter();
      switch (input)
        {
          case ARROW_UP:
            temple -> getPlayer() -> move(Actor::UP);
            play();
            break;
          case ARROW_DOWN:
            temple -> getPlayer() -> move(Actor::DOWN);
            play();
            break;
          case ARROW_RIGHT:
            temple -> getPlayer() -> move(Actor::RIGHT);
            play();
            break;
          case ARROW_LEFT:
            temple -> getPlayer() -> move(Actor::LEFT);
            play();
            break;
        }
    }
}