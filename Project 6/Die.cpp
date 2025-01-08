//
//  Die.cpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#include "Die.h"
#include <iostream>
using namespace std;
#include <random>

namespace cs31
{
    
    Die::Die( int sides ) : mSides( sides ), mValue( 1 )
    {

    }
    
    void Die::roll()
    {
        random_device rd;
        mt19937 e2(rd());
        uniform_int_distribution<> dist(1, mSides);
        mValue = dist(e2);
    }
    
    int  Die::getValue( ) const
    {
        return( mValue );
    }

    void Die::setValue( int amount )
    {
        mValue = amount;
    }

}


