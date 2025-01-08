//
//  BeetleGame.cpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"
#include "Beetle.h"
#include <iostream>
using namespace std;

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
string BeetleGame::display( string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    string result = drawing.draw() + "\n" + msg;
    return( result );
}


void BeetleGame::humanRoll( int amount )
{
    // if the amount is zero, roll the Human's die
    if (amount == 0)
    {
        mHumanDie.roll();
    }
//   cheat by giving human an amount
    else
    {
        mHumanDie.setValue(amount);
    }
}

int BeetleGame::getHumanDie( ) const
{
    return mHumanDie.getValue();
    return( -1 );
}

bool BeetleGame::humanPlay( )
{
//    convert die's value into a Beetle's body part
    Beetle::BodyPart part = mHuman.convertRollToBodyPart( mHumanDie.getValue() );
    
//  game ordering of body parts
    if(part == Beetle::BodyPart::EYE)
    {
//      Beetle musst have a body and head before adding an eye
        if((!mHuman.hasEye1() || !mHuman.hasEye2()) && mHuman.hasBody() && mHuman.hasHead())
        {
            mHuman.buildEye();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::ANTENNA)
    {
//      Beetle must have body and head before adding an antenna
        if((!mHuman.hasAntenna1() || !mHuman.hasAntenna2()) && mHuman.hasHead() && mHuman.hasBody())
        {
            mHuman.buildAntenna();
            return true;
        }
    }
            
    if(part == Beetle::BodyPart::LEG)
    {
//      Beetle must have body before adding a leg
        if((!mHuman.hasLeg1()|| !mHuman.hasLeg2() || !mHuman.hasLeg3() || !mHuman.hasLeg4()) && mHuman.hasBody())
        {
            mHuman.buildLeg();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::TAIL)
    {
//      Beetle must have body before adding a tail
        if(!mHuman.hasTail() && mHuman.hasBody())
        {
            mHuman.buildTail();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::HEAD)
    {
//      Beetle must have body before adding a head
        if(!mHuman.hasHead() && mHuman.hasBody())
        {
            mHuman.buildHead();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::BODY)
    {
            if(!mHuman.hasBody())
            {
                mHuman.buildBody();
                return true;
            }
    }

    return( false );
}

void BeetleGame::computerRoll( int amount )
{
    // if the amount is zero, roll the Computer's die
    if(amount == 0)
    {
        mComputerDie.roll();
    }
//  cheat by giving computer an amount
    else
    {
        mComputerDie.setValue(amount);
    }
}

int BeetleGame::getComputerDie( ) const
{
//  return value of computer roll
    return(mComputerDie.getValue());
    return( -1 );
}


bool BeetleGame::computerPlay( )
{
//    convert die's value into a Beetle's body part
    Beetle::BodyPart part = mComputer.convertRollToBodyPart( mComputerDie.getValue() );
    
    if(part == Beetle::BodyPart::EYE)
    {
//      Beetle must have body and head before adding an eye
        if((!mComputer.hasEye1() || !mComputer.hasEye2()) && mComputer.hasBody() && mComputer.hasHead())
        {
            mComputer.buildEye();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::ANTENNA)
    {
//      Beetle must have a body and head before adding an antenna
        if((!mComputer.hasAntenna1() || !mComputer.hasAntenna2()) && mComputer.hasHead() && mComputer.hasBody())
        {
            mComputer.buildAntenna();
            return true;
        }
    }
            
    if(part == Beetle::BodyPart::LEG)
    {
//      Beetle must have a body before adding a leg
        if((!mComputer.hasLeg1()|| !mComputer.hasLeg2() || !mComputer.hasLeg3() || !mComputer.hasLeg4()) && mComputer.hasBody())
        {
            mComputer.buildLeg();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::TAIL)
    {
//      Beetle must have a body before adding a tail
        if(!mComputer.hasTail() && mComputer.hasBody())
        {
            mComputer.buildTail();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::HEAD)
    {
//      Beetle must have a body before adding a head
        if(!mComputer.hasHead() && mComputer.hasBody())
        {
            mComputer.buildHead();
            return true;
        }
    }
    
    if(part == Beetle::BodyPart::BODY)
    {
            if(!mComputer.hasBody())
            {
                mComputer.buildBody();
                return true;
            }
    }

    return( false );
}

//  what is the status of the game?
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{
    if(mHuman.isComplete() && !mComputer.isComplete())
    {
        return GameOutcome::HUMANWONGAME;
    }
    else if(!mHuman.isComplete() && mComputer.isComplete())
    {
        return GameOutcome::COMPUTERWONGAME;
    }
    else
    {
        return( GameOutcome::GAMENOTOVER );
    }

}

string  BeetleGame::stringifyGameOutcome( ) const
{
    string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// is there a winner?
bool BeetleGame::gameIsOver() const
{
    if(mHuman.isComplete() || mComputer.isComplete())
    {
        return(true);
    }
    else
    {
        return false;
    }
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}



