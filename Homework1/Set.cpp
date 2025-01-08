#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
{
    ItemType arr[0];
}

bool Set::empty() const
{
    if(sizeof(arr) == 0)
    {
        return true;
    }
    return false;
}

int Set::size() const
{
    int sizenum = 0;
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if(sizeof(arr) != 0)
        {
            sizenum++;
        }
    }
    return sizenum;
}

bool Set::insert(const ItemType& value)
{
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        if(arr[i] != value)
        {
            return false;
        }
    }

    if(sizeof(arr) != DEFAULT_MAX_ITEMS)
    {
        arr[size() + 1] = value;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
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
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
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
    if(0 <= i < size())
    {
        int item = 0;
        for(int j = 0; j < size(); j++)
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

void Set::swap(Set& other)
{
    ItemType newArr;
    for(int i = 0; i < size(); i++)
    {
        newArr = arr[i];
        arr[i] = other.arr[i];
        other.arr[i] = newArr;
    }
}

