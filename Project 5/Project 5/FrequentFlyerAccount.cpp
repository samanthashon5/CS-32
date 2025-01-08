//
//  FrequentFlyerAccount.cpp
//  Project 5
//
//  Created by Samantha Shon on 3/2/24.
//
#include <iostream>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;

    
//    constructor
FrequentFlyerAccount::FrequentFlyerAccount(string name)
{
//    make sure that the name is returned
    mName = name;
}
//    accessors
double FrequentFlyerAccount::getBalance()
{
    return(mBalance);
}
string FrequentFlyerAccount::getName()
{
    return(mName);
}

//increase mileage balance
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight)
{
//    check if names are the same
    if (flight.getName() == mName)
    {
        mBalance += flight.getMileage();
        return true;
    }
    return false;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight)
{
//    check if there is enough mileage balance
    if (mBalance >= mileage)
    {
//      reassign all of the setters
        flight.setName(mName);
        flight.setCost(0);
        flight.setFromCity(from);
        flight.setToCity(to);
        flight.setMileage(mileage);
//      adjust the mileage balance
        mBalance -= mileage;
        return true;
    }
    return false;
}


    
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage)
{
//    check if mileage balance covers the length of the flight
    return mBalance >= mileage;
}



