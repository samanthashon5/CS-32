//
//  array.cpp
//  Project 4
//
//  Created by Samantha Shon on 2/13/24.
//

#include <iostream>
#include <cassert>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int locateMaximum( const string array [], int n );
int countFloatingPointValues( const string array [], int n );
bool hasNoCapitals( const string array[], int n );
int shiftLeft( string array[], int n, int amount, string placeholder );

// extra functions that are needed
bool isAfloat (string a);


//int main()
//{
//    string array[8] = { "123", "456", "789", "gamma", "beta", "delta", "1.2.3", "hEllo"};
//    assert( locateMaximum (array,6) == 3);
//    assert( countFloatingPointValues (array,8) == 3);
//    assert( hasNoCapitals (array, 8) == false);
//    assert( shiftLeft (array, 6, -2, "foo") == -1);
    
//    string array [3] = {""};
//    assert( shiftLeft (array, 3, 1, "hey") == -1);
//    
//    cout << "all tests succeded" << endl;
//    return 0;
//}

int locateMaximum( const string array [], int n)
{
    int max = 0;
//  check if array amount is less than or equal to 0
    if ( n <= 0 )
    {
        return -1;
    }
    for ( int i = 0; i < n; i++ )
    {
//      check for an empty string
        if ( array[i].empty() )
        {
            return -1;
        }
        if ( array[i] > array [max] )
        {
            max = i;
        }
    }
    return max;
}

//check for decimals or digits
bool isAfloat ( const string a )
{
//  check for an empty string
    if (a.empty())
    {
        return false;
    }
    bool isDecimal = false;
    for ( char b : a )
    {
        if ( b == '.')
        {
//          make sure there are no repeating decimals
            if( b == '.')
            {
                isDecimal = false;
            }
            isDecimal = true;
        }
//      if b is not a decimal, is it a digit
        else if ( !isdigit (b) )
        {
            return false;
        }
    }
    return true;
}

// add all floats in array together
int countFloatingPointValues( const string array [], int n )
{
    int floatingPoint = 0;
//  array amount must be less than or equal to 0
    if (n <= 0)
    {
        return -1;
    }
    for ( int i = 0; i < n; i++ )
    {
        if ( isAfloat (array [i]))
        {
            floatingPoint++;
        }
    }
    return floatingPoint;
}

//check for capital letters
bool hasNoCapitals( const string array[], int n )
{
//  check if array amount is less than or equal to 0
    if( n <= 0 )
    {
        return -1;
    }
    for( int i = 0; i < n; i++)
    {
        string a = array [i];
//      look through all characters in a string
        for ( char b : a)
        {
            if (b >= 'A' && b <= 'Z')
            {
                return false;
            }
        }
    }
    return true;
}

//shift strings to the left
int shiftLeft( string array[], int n, int amount, string placeholder )
{
    int result = -1;
//  check if array amount or amount of shifts is less than or equal to 0
    if( n <= 0 || amount < 0)
    {
        return -1;
    }
    result = 0;
//  shift until it reaches inputted amount
    for( int j = 0; j < amount; j++)
    {
        for( int i = 0; i < n - 1; i++)
        {
//          check for empty strings
            if ( array[i].empty())
            {
                return -1;
            }
//          shifting strings
            array[i] = array[i++];
        }
//      string replacement
        array[ n - 1] = placeholder;
//      number returned
        result = amount;
    }
    return (result);
}
           
