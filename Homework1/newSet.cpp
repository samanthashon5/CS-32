#include "newSet.h"
#include <iostream>
#include <utility>
#include <cstdlib>
using namespace std;

//destructor, copy constructor, assignment operator

//add new or modifiy existing constructor
Set::Set(int m_Max)
{
    this->m_Max = m_Max;
    arr = new ItemType[m_Max];
    sizenum = 0;
}

//destructor
Set::~Set()
{
    delete []arr;
}

//copy constructor
Set::Set(const Set& other)
{
    arr = new ItemType[other.m_Max];
    m_size = other.m_size;
    m_Max = other.m_Max;
    for(int i = 0; i < m_size; i++)
    {
        arr[i] = other.arr[i];
    }
}

//assignment operator
Set& Set::operator=(const Set& other)
{
    if(this != &other)
    {
        ItemType* temp = new ItemType[other.m_Max];
        for(int i = 0; i < other.m_size; i++)
        {
            temp[i] = other.arr[i];
        }

        delete [] arr;
        arr = temp;
        m_size = other.m_size;
        m_Max = other.m_Max;
    }
    return *this;
}

bool Set::empty() const
{
    if(sizenum == 0)
    {
        return true;
    }
    return false;
}

int Set::size() const
{
    return sizenum;
}

bool Set::insert(const ItemType& value)
{
    for(int i = 0; i < m_Max; i++)
    {
        if(arr[i] != value)
        {
            return false;
        }
    }

    if(sizeof(arr) < m_Max)
    {
        arr[size() + 1] = value;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
    for(int i = 0; i < m_Max; i++)
    {
        if(arr[i] == value)
        {
            for(int j = i; j < size() - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[size() - 1] = ItemType();
            return true;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const
{
    for(int i = 0; i < m_Max; i++)
    {
        if(arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const
{
    if(i >= 0 && i < m_size)
    {
        int item = 0;
        for(int j = 0; j < m_size; j++)
        {
            if(j < i)
            {
                item++;
            }
        }
        value = arr[item];
        return true;
    }
    else
    {
        return false;
    }
}

//number of statement executions when swapping two sets is the same no matter how many items are in the sets
void Set::swap(Set& other) 
{
    ItemType* temp = arr;
    arr = other.arr;
    other.arr = temp;

    int m_sizetemp = m_size;
    m_size = other.m_size;
    other.m_size = m_sizetemp;

    int m_Maxtemp = m_Max;
    m_Max = other.m_Max;
    other.m_Max = m_Maxtemp;
}
    