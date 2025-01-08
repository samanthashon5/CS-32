//
//  Die.hpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//
#include <iostream>
#ifndef Die_h
#define Die_h

namespace cs31
{
    

class Die
{
public:
    Die( int sides = 6 ); // by default, a six sided die
    void roll();
    int  getValue( ) const;
    void setValue( int amount );
private:
    int  mSides;
    int  mValue;
};

    
}
#endif /* Die_h */

