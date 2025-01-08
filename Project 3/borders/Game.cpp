// Game.cpp

#include "Game.h"
#include "utilities.h"
#include <iostream>
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance):m_distance(goblinSmellDistance) {
    //draw borders
      int r, c;

      for (r = 0; r < 18; r++) {
        grid[r][0] = '#';
      }

      for (r = 0; r < 18; r++) {
        grid[r][69] = '#';
      }

      for (c = 0; c < 70; c++) {
        grid[0][c] = '#';
      }

      for (c = 0; c < 70; c++) {
        grid[17][c] = '#';
      }
}

// You will presumably add to this project other .h/.cpp files for the various
// classes of objects you need to play the game:  player, monsters, weapons,
// etc.  You might have a separate .h/.cpp pair for each class (e.g., Player.h,
// Bogeyman.h, etc.), or you might put the class declarations for all actors in
// Actor.h, all game objects in GameObject.h, etc.

// void Temple::display() {
//   // Position (row,col) in the city coordinate system is represented in
//   // the array element grid[row-1][col-1]

// //draw borders
//   char grid[18][70];
//   int r, c;

//   for (r = 0; r < 18; r++) {
//     grid[r][0] = '#';
//   }

//   for (r = 0; r < 18; r++) {
//     grid[r][69] = '#';
//   }

//   for (c = 0; c < 70; c++) {
//     grid[0][c] = '#';
//   }

//   for (c = 0; c < 70; c++) {
//     grid[17][c] = '#';
//   }
// }

void Game::draw() {
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < 70; j++)
      cout << grid[i][j];
    cout << endl;
  }
  cout << endl;
}

// Indicate each Tooter's position

void Game::play()
{
    draw();
    cout << "The game hasn't been implemented yet." << endl;
    cout << "Press q to exit game." << endl;
    while (getCharacter() != 'q')
        ;
}



