//
//  main.cpp
//  FrequentFlyerAccount
//
//  Created by Samantha Shon on 3/2/24.
//

#include <iostream>
#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
using namespace std;

    string mName;
    double mBalance;
    
//    constructor
    FrequentFlyerAccount::FrequentFlyerAccount(string name)
    {
        name = mName;
    }
//    accessors
    double FrequentFlyerAccount::getBalance()
    {
        return getBalance();
    }
    string FrequentFlyerAccount::getName()
    {
        return getName();
    }
    
    bool addFlightToAccount(PlaneFlight flight)
    {
        if (flight.getName() == mName)
        {
            mBalance += flight.getMileage();
            return true;
        }
        return false;
    }
    
    bool canEarnFreeFlight(double mileage)
    {
        if (mBalance >= mileage)
        {
            return true;
        }
        return false;
    }
            
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight)
    {
        if (mBalance >= mileage)
        {
            mBalance -= mileage;
            return true;
        }
        return false;
    }

