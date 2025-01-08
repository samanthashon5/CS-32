//
//  main.cpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#include <iostream>
#include <string>
#include <cassert>

#include "Die.h"
#include "Beetle.h"
#include "BeetleDrawing.h"
#include "BeetleGame.h"
using namespace std;

int main()
{
    using namespace cs31;
    using namespace std;

// sample test code working with Die
    Die d;
    d.roll();
    int value = d.getValue();
    assert( value >= 1 && value <= 6 );

// sample test code working with Beetle
    Beetle b;

// beetle does what you tell it to do, not enforce rules of the game.
// rules of the game are left to BeetleGame to implement

    assert( b.hasHead() == false );
    assert( b.isComplete() == false );
    b.buildHead();
    assert( b.hasHead());
    assert( b.isComplete() == false );

             // build Leg1 before Leg2 before Leg3 before Leg4
             assert( b.hasLeg1() == false );
             assert( b.hasLeg2() == false );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             assert( b.isComplete() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() == false );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() );
             assert( b.hasLeg4() );
             assert( b.isComplete() == false );

             // build Eye1 before Eye2
             assert( b.hasEye1() == false );
             assert( b.hasEye2() == false );
             assert( b.isComplete() == false );
             b.buildEye();
             assert( b.hasEye1() );
             assert( b.hasEye2() == false );
             b.buildEye();
             assert( b.hasEye1() );
             assert( b.hasEye2() );
             assert( b.isComplete() == false );

             assert( b.hasTail() == false );
             assert( b.isComplete() == false );
             b.buildTail();
             assert( b.hasTail() );
             assert( b.isComplete() == false );

             // build Antenna1 before Antenna2
             assert( b.hasAntenna1() == false );
             assert( b.hasAntenna2() == false );
             assert( b.isComplete() == false );
             b.buildAntenna();
             assert( b.hasAntenna1() );
             assert( b.hasAntenna2() == false );
             b.buildAntenna();
             assert( b.hasAntenna1() );
             assert( b.hasAntenna2() );
             assert( b.isComplete() == false );

             assert( b.hasBody() == false );
             assert( b.isComplete() == false );
             b.buildBody();
             assert( b.hasBody() );
             assert( b.isComplete() == true );

             // cheating play
             BeetleGame game;
             assert( game.gameIsOver() == false );
             game.humanRoll( 1 );
             game.humanPlay();
             game.computerRoll( 1 );
             game.computerPlay();
             assert( game.getHumanBeetle().isComplete() == false );
             assert( game.getHumanBeetle().hasBody() == false );
             assert( game.getComputerBeetle().isComplete() == false );
             assert( game.getComputerBeetle().hasBody() == false );
             assert( game.gameIsOver() == false );
             game.humanRoll( 6 );
             game.humanPlay();
             game.computerRoll( 6 );
             game.computerPlay();
             assert( game.getHumanBeetle().isComplete() == false );
             assert( game.getHumanBeetle().hasBody() );
             assert( game.getComputerBeetle().isComplete() == false );
             assert( game.getComputerBeetle().hasBody() );
    
            // order of body parts
            BeetleGame bodyparts;
            bodyparts.humanRoll(1);
            bodyparts.humanPlay();
            bodyparts.computerRoll(2);
            bodyparts.computerPlay();
            assert( bodyparts.getHumanBeetle().hasEye1() == false);
            assert( bodyparts.getComputerBeetle().hasAntenna1() == false);
            bodyparts.humanRoll(6);
            bodyparts.humanPlay();
            bodyparts.computerRoll(6);
            bodyparts.computerPlay();
            assert(bodyparts.getHumanBeetle().hasEye1() == false);
            assert(bodyparts.getHumanBeetle().hasBody() == true);
            assert(bodyparts.getComputerBeetle().hasAntenna1() == false);
            assert(bodyparts.getComputerBeetle().hasBody() == true);
            bodyparts.humanRoll(2);
            bodyparts.humanPlay();
            bodyparts.computerRoll(1);
            bodyparts.computerPlay();
            assert(bodyparts.getHumanBeetle().hasAntenna1() == false);
            assert(bodyparts.getHumanBeetle().hasEye2() == false);
            assert(bodyparts.getComputerBeetle().hasEye1() == false);
            bodyparts.humanRoll(5);
            bodyparts.humanPlay();
            bodyparts.computerRoll(4);
            bodyparts.computerPlay();
            assert(bodyparts.getHumanBeetle().hasHead() == true);
            assert(bodyparts.getHumanBeetle().hasEye2() == false);
            assert(bodyparts.getComputerBeetle().hasTail() == true);
            bodyparts.humanRoll(1);
            bodyparts.humanPlay();
            bodyparts.computerRoll(5);
            bodyparts.computerPlay();
            assert(bodyparts.getHumanBeetle().hasEye1() == true);
            assert(bodyparts.getHumanBeetle().hasEye2() == false);
            assert(bodyparts.getComputerBeetle().hasHead() == true);
            bodyparts.humanRoll(1);
            bodyparts.humanPlay();
            bodyparts.computerRoll(2);
            bodyparts.computerPlay();
            assert(bodyparts.getHumanBeetle().hasEye1() == true);
            assert(bodyparts.getHumanBeetle().hasEye2() == true);
            assert(bodyparts.getComputerBeetle().hasAntenna1() == true);
            assert(bodyparts.getComputerBeetle().hasAntenna2() == false);
    
    
        //  test game outcomes
            BeetleGame outcomes;
            outcomes.humanRoll(6);
            outcomes.humanPlay();
            outcomes.computerRoll(5);
            outcomes.computerPlay();
            outcomes.humanRoll(5);
            outcomes.humanPlay();
            outcomes.computerRoll(6);
            outcomes.computerPlay();
            outcomes.humanRoll(4);
            outcomes.humanPlay();
            outcomes.computerRoll(5);
            outcomes.computerPlay();
            outcomes.humanRoll(3);
            outcomes.humanPlay();
            outcomes.computerRoll(4);
            outcomes.computerPlay();
            outcomes.humanRoll(3);
            outcomes.humanPlay();
            outcomes.computerRoll(3);
            outcomes.computerPlay();
            outcomes.humanRoll(3);
            outcomes.humanPlay();
            outcomes.computerRoll(3);
            outcomes.computerPlay();
            outcomes.humanRoll(3);
            outcomes.humanPlay();
            outcomes.computerRoll(3);
            outcomes.computerPlay();
            outcomes.humanRoll(2);
            outcomes.humanPlay();
            outcomes.computerRoll(3);
            outcomes.computerPlay();
            outcomes.humanRoll(2);
            outcomes.humanPlay();
            outcomes.computerRoll(2);
            outcomes.computerPlay();
            outcomes.humanRoll(1);
            outcomes.humanPlay();
            outcomes.computerRoll(2);
            outcomes.computerPlay();
            outcomes.humanRoll(1);
            outcomes.humanPlay();
            outcomes.computerRoll(3);
            outcomes.computerPlay();
            assert(outcomes.getHumanBeetle().isComplete() == true);
            assert(outcomes.gameIsOver() == true);
            assert(outcomes.determineGameOutcome() == cs31::BeetleGame::GameOutcome::HUMANWONGAME);
            assert(outcomes.stringifyGameOutcome() == "Human Won!");
    
        //  test game outcomes
            BeetleGame incomplete;
            incomplete.humanRoll(6);
            incomplete.humanPlay();
            incomplete.computerRoll(5);
            incomplete.computerPlay();
            incomplete.humanRoll(5);
            incomplete.humanPlay();
            incomplete.computerRoll(6);
            incomplete.computerPlay();
            incomplete.humanRoll(4);
            incomplete.humanPlay();
            incomplete.computerRoll(5);
            incomplete.computerPlay();
            assert(incomplete.getHumanBeetle().isComplete() == false);
            assert(incomplete.gameIsOver() == false);
            assert(incomplete.determineGameOutcome() == cs31::BeetleGame::GameOutcome::GAMENOTOVER);
            assert(incomplete.stringifyGameOutcome() == "Game Not Over!");
        
        //    test game outcomes
            BeetleGame tie;
            tie.humanRoll(6);
            tie.humanPlay();
            tie.computerRoll(6);
            tie.computerPlay();
            tie.humanRoll(5);
            tie.humanPlay();
            tie.computerRoll(5);
            tie.computerPlay();
            tie.humanRoll(4);
            tie.humanPlay();
            tie.computerRoll(4);
            tie.computerPlay();
            tie.humanRoll(3);
            tie.humanPlay();
            tie.computerRoll(3);
            tie.computerPlay();
            tie.humanRoll(3);
            tie.humanPlay();
            tie.computerRoll(3);
            tie.computerPlay();
            tie.humanRoll(3);
            tie.humanPlay();
            tie.computerRoll(3);
            tie.computerPlay();
            tie.humanRoll(3);
            tie.humanPlay();
            tie.computerRoll(3);
            tie.computerPlay();
            tie.humanRoll(2);
            tie.humanPlay();
            tie.computerRoll(2);
            tie.computerPlay();
            tie.humanRoll(2);
            tie.humanPlay();
            tie.computerRoll(2);
            tie.computerPlay();
            tie.humanRoll(1);
            tie.humanPlay();
            tie.computerRoll(1);
            tie.computerPlay();
            tie.humanRoll(1);
            tie.humanPlay();
            tie.computerRoll(1);
            tie.computerPlay();
            assert(tie.gameIsOver() == true);
            assert(tie.determineGameOutcome() == cs31::BeetleGame::GameOutcome::GAMENOTOVER);
            assert(tie.stringifyGameOutcome() == "Game Not Over!");

            cout << "all tests passed!" << endl;
            return( 0 );
}
