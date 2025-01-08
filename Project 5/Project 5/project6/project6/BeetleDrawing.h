//
//  BeetleDrawing.hpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#ifndef BeetleDrawing_h
#define BeetleDrawing_h
#include <iostream>
#include <string>
#include "Beetle.h"
using namespace std;

namespace cs31
{


class BeetleDrawing
{
public:
    BeetleDrawing( Beetle playerBeetle, Beetle computerBeetle );
    
    // draw one line at a time
    string draw( int lineNumber );
    // draw all six lines
    string draw( );
    
private:
    Beetle mPlayer, mComputer;
};


}

#endif

