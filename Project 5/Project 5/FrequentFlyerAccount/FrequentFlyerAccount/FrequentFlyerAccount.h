//
//  FrequentFlyerAccount.h
//  FrequentFlyerAccount
//
//  Created by Samantha Shon on 3/2/24.
//
#include <iostream>
#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h
using namespace std;

class FrequentFlyerAccount
{
private:
    string mName;
    double mBalance;
    
public:
//    constructor
    FrequentFlyerAccount(string name);
//    accessors
    double getBalance();
    string getName();
    
    bool addFlightToAccount(PlaneFlight flight);
    
    bool canEarnFreeFlight(double mileage);
            
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);
};

#endif /* FrequentFlyerAccount_h */
