//
//  Beetle.cpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//
#include <iostream>
#include "Beetle.h"
using namespace std;
namespace cs31
{

Beetle::Beetle()
{
    mBody = false;
    mTail = false;
    mLeg1 = false;
    mLeg2 = false;
    mLeg3 = false;
    mLeg4 = false;
    mHead = false;
    mEye1 = false;
    mEye2 = false;
    mAntenna1 = false;
    mAntenna2 = false;
}

// convert a tossed die value into a BodyPart
Beetle::BodyPart Beetle::convertRollToBodyPart( int die ) const
{
    // if not matching, then return NOTVALID
    BodyPart part = BodyPart::NOTVALID;
    if (die == 6)
        part = BodyPart::BODY;
    if (die == 5)
        part = BodyPart::HEAD;
    if (die == 4)
        part = BodyPart::TAIL;
    if (die == 3)
        part = BodyPart::LEG;
    if (die == 2)
        part = BodyPart::ANTENNA;
    if (die == 1)
        part = BodyPart::EYE;
    return( part );
}

// build the Beetle's body
void Beetle::buildBody()
{
    // for now...
    mBody = true;
}

// has the Beetle's body been built?
bool Beetle::hasBody() const
{
    // for now...
    return (mBody);
    //    return( false );
}

// build the Beetle's tail but only if the body has already been built
void Beetle::buildTail()
{
    // for now...
    mTail = true;
}

// has the Beetle's tail been built?
bool Beetle::hasTail() const
{
    // for now...
    return (mTail);
    //    return( false );
}

// build the Beetle's leg but only if the body has already been built
void Beetle::buildLeg()
{
    // for now...
    if(!mLeg1)
    {
        mLeg1 = true;
        return;
    }
    
    if(!mLeg2 && mLeg1)
    {
        mLeg2 = true;
        return;
    }
    
    if(!mLeg3 && mLeg1 && mLeg2)
    {
        mLeg3 = true;
        return;
    }
    
    if(!mLeg4 && mLeg1 && mLeg2 && mLeg3)
    {
        mLeg4 = true;
        return;
    }
}

// has the Beetle's leg been built?
bool Beetle::hasLeg1() const
{
    // for now...
    return(mLeg1);
    //    return( false );
}

bool Beetle::hasLeg2() const
{
    // for now...
    return(mLeg2);
    //    return( false );
}

bool Beetle::hasLeg3() const
{
    // for now...
    return(mLeg3);
    //    return( false );
}

bool Beetle::hasLeg4() const
{
    // for now...
    return(mLeg4);
    //    return( false );
}

// build the Beetle's head but only if the body has already been built
void Beetle::buildHead()
{
    // for now...
    mHead = true;
    
}

// has the Beetle's head been built?
bool Beetle::hasHead() const
{
    // for now...
    return(mHead);
    //    return( false );
}

// build the Beetle's eye but only if the head has already been built
void Beetle::buildEye()
{
    // for now...
    if(!mEye1)
    {
        mEye1 = true;
        return;
    }
    if(!mEye2 && mEye1)
    {
        mEye2 = true;
        return;
    }
}

// has the Beetle's eye been built?
bool Beetle::hasEye1() const
{
    // for now...
    return(mEye1);
    //    return( false );
}

bool Beetle::hasEye2() const
{
    // for now...
    return(mEye2);
    //    return( false );
}

// build the Beetle's antenna but only if the head has already been built
void Beetle::buildAntenna()
{
    // for now...
    if(!mAntenna1)
    {
        mAntenna1 = true;
        return;
    }
    
    if(!mAntenna2 && mAntenna1)
    {
        mAntenna2 = true;
        return;
    }
}

// has the Beetle's antenna been built?
bool Beetle::hasAntenna1() const
{
    // for now...
    return(mAntenna1);
    //    return( false );
}

bool Beetle::hasAntenna2() const
{
    // for now...
    return(mAntenna2);
    //    return( false );
}


// is this Beetle completely built out?
bool Beetle::isComplete() const
{
    // for now...
    if (mBody && mTail && mLeg1 && mLeg2 && mLeg3 && mLeg4 && mHead && mEye1 && mEye2 && mAntenna1 && mAntenna2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

}

