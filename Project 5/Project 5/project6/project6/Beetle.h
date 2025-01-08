//
//  Beetle.hpp
//  project6
//
//  Created by Samantha Shon on 3/12/24.
//

#ifndef Beetle_h
#define Beetle_h
#include <iostream>
#include <string>


namespace cs31
{


class Beetle
{
public:
    enum class BodyPart { EYE = 1, ANTENNA = 2, LEG = 3,
        TAIL = 4, HEAD = 5, BODY = 6, NOTVALID = 7 };
    
    Beetle();
    
    Beetle::BodyPart convertRollToBodyPart( int die ) const;
    
    void buildBody();
    bool hasBody() const;
    
    void buildTail();
    bool hasTail() const;
    
    void buildLeg();
    bool hasLeg1() const;
    bool hasLeg2() const;
    bool hasLeg3() const;
    bool hasLeg4() const;
    
    void buildHead();
    bool hasHead() const;
    
    void buildEye();
    bool hasEye1() const;
    bool hasEye2() const;
    
    void buildAntenna();
    bool hasAntenna1() const;
    bool hasAntenna2() const;
    
    
    bool isComplete() const;
private:
    bool mBody, mTail, mLeg1, mLeg2, mLeg3, mLeg4, mHead, mEye1, mEye2, mAntenna1, mAntenna2;
    
};

}


#endif
