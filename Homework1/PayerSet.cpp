#include "PayerSet.h"
#include <iostream>
using namespace std;

PayerSet::PayerSet()
{

}

//no suitable constructor exists to convert accountNum
bool PayerSet::add(unsigned long accountNum)
{
    if(payerSet.contains(accountNum))
    {
        return false;
    }
    if(payerSet.size() >= DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        payerSet.insert(accountNum);
        return true;
    }
}

int PayerSet::size() const
{
    return payerSet.size();
}

//can use for loop but can't use open square brackets
void PayerSet::print() const
{
    for(int i = 0; i < size(); i++)
    {
        ItemType x;
        payerSet.get(i, x);
        cout << x << endl;
    }
}


