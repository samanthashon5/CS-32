//
//  PlaneFlight.h
//  Project 5
//
//  Created by Samantha Shon on 3/2/24.
//
#include <iostream>
#ifndef PlaneFlight_h
#define PlaneFlight_h
using namespace std;

class PlaneFlight
{
private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;
    
public:
//  constructor
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
//  accessors
    double getCost();
    double getMileage();
    string getName();
    string getFromCity();
    string getToCity();
    
//  mutators
    void setCost(double cost);
    void setMileage(double mileage);
    void setName(string name);
    void setFromCity(string from);
    void setToCity(string to);
};

#endif /* PlaneFlight_h */
