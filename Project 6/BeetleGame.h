//
//  BeetleGame.hpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#ifndef BeetleGame_h
#define BeetleGame_h
#include <iostream>
#include "Die.h"
#include "Beetle.h"
#include <string>
using namespace std;
namespace cs31
{
    
    class BeetleGame
    {
    public:
        BeetleGame();
        
        enum class GameOutcome { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        string display( string msg = "" ) const;
        
        // when amount is zero, it is a random roll...
        // otherwise, an amount value is a cheating value...
        void humanRoll( int amount = 0 );
        int getHumanDie( ) const;
        bool humanPlay( );
        
        // when amount is zero, it is a random roll...
        // otherwise, an amount value is a cheating value...
        void computerRoll( int amount = 0 );
        int getComputerDie( ) const;
        bool computerPlay( );
        
        GameOutcome  determineGameOutcome( ) const;
        string  stringifyGameOutcome( ) const;
        bool gameIsOver() const;
        
        // for testing purposes
        Beetle getHumanBeetle( ) const;
        Beetle getComputerBeetle( ) const;
    private:
        Beetle mHuman,    mComputer;
        Die    mHumanDie, mComputerDie;
    };
    
}

#endif
