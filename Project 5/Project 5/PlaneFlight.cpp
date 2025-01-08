//
//  PlaneFlight.cpp
//  Project 5
//
//  Created by Samantha Shon on 2/27/24.
//

#include <iostream>
using namespace std;
#include "PlaneFlight.h"
    
//    constructor
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage)
{
    setName (passengerName);
    setFromCity(fromCity);
    setToCity(toCity);
    setCost(cost);
    setMileage (mileage);
    //    cost can't be less than 0
    if (cost < 0)
    {
        cost = -1;
    }
    else
    {
        mCost = cost;
    }
//    mileage must be a value greater than 0
    if (mileage <= 0)
    {
        mileage = -1;
    }
    else
    {
        mMileage = mileage;
    }
//    no empty strings
    if (!fromCity.empty())
    {
        mFromCity = fromCity;
    }
//    FromCity and ToCity must be different and no empty strings
    if (!toCity.empty() && toCity != fromCity)
    {
        mToCity = toCity;
    }
//    no empty strings
    if (!passengerName.empty())
    {
        mName = passengerName;
    }
}

//  accessors
double PlaneFlight::getCost()
{
    return(mCost);
}
double PlaneFlight::getMileage()
{
    return(mMileage);
}
string PlaneFlight::getName()
{
    return(mName);
}
string PlaneFlight::getFromCity()
{
    return(mFromCity);
}
string PlaneFlight::getToCity()
{
    return(mToCity);
}
    
//  mutators
void PlaneFlight::setCost(double cost)
{
//    cost cannot be less than zero
    if (cost < 0)
    {
        mCost = -1;
    }
    else
    {
        mCost = cost;
    }
}
void PlaneFlight::setMileage(double mileage)
{
//    mileage must be greater than zero
    if (mileage <= 0)
    {
        mMileage = -1;
    }
    else
    {
        mMileage = mileage;
    }
}
void PlaneFlight::setName(string name)
{
//    passenger name cannot be blank
    if (!name.empty())
    {
        mName = name;
    }
}
void PlaneFlight::setFromCity(string from)
{
//    originating city cannot be blank
    if (!from.empty())
    {
        mFromCity = from;
    }
}
void PlaneFlight::setToCity(string to)
{
//    cities cannot be the same and destination city must not be empty
    if (!to.empty() && to != mFromCity)
    {
        mToCity = to;
    }
}

