//
//  main.cpp
//  Project 3
//
//  Created by Samantha Shon on 2/8/24.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidQC (string results);
int passQC (string results);
int defectQC (string results);
int totalQC (string results);
int batches (string results);

int main ()
{
    assert (isValidQC ("Q2p1d1") == 1);
    assert (isValidQC ("Q2d1p1Q5p3d2") == 1);
    assert (isValidQC ("Q2d1p0") == 0);
    assert (isValidQC ("Q2d1p1 asdf") == 0);
    assert (isValidQC (" ") == 0);
    assert (isValidQC ("q1p0d1") == 0);
    assert (isValidQC ("Q3pd3") == 0);
    assert (isValidQC ("Q3p3d") == 0);
    assert (isValidQC ("Q5p000003d000002") == 0);
    assert (isValidQC ("Q0p0d0") == 0);
    assert (isValidQC ("Q5p3d2") == 1);
    assert (isValidQC ("Q22p11d11")== 1);
}

bool isValidQC(string results) {
    int passes = 0;
    int defects = 0;
    int tests = 0;
    
//  string can't be empty
    if (results.empty()) 
    {
        return false;
    }
    
// string must start with 'Q'
    if (results[0] != 'Q') 
    {
        return false;
    }
    
    for (int qpd = 0; qpd < results.size(); qpd++) 
    {
//       'Q' must be followed by a digit
        if (results[0] == 'Q' && !isdigit(results[1]))
        {
        return false;
        }
    
//      the digit after 'Q' must not be zero
        if (results[qpd] == 'Q' && results[qpd + 1] == '0')
        {
            return false;
        }
        
//       retrieve number of tests
        if (results[qpd] == 'Q' && isdigit(results[qpd + 1]))
        {
            tests += results[qpd + 1] - '0';
        }
        
//        'p' must be followed by a digit
        if (results [qpd] == 'p' && !isdigit (results [qpd + 1]))
        {
            return false;
        }
        
//      retrieve number of passes
        if (results[qpd] == 'p' && isdigit(results[qpd + 1]))
        {
            passes += results[qpd + 1] - '0';
        }
        
//        'd' must be followed by a digit
        if (results [qpd] == 'd' && !isdigit (results [qpd + 1]))
        {
            return false;
        }
        
//      retrieve number of defects
        if (results[qpd] == 'd' && isdigit(results[qpd + 1]))
        {
            defects += results[qpd + 1] - '0';
        }
    
//       no leading zeros after 'Q', 'p', or 'd'
        if (results[qpd] == '0' && isdigit(results[qpd - 1])) 
        {
            return false;
        }

//      no excess characters
        if (results [qpd] != 'Q' && results [qpd] != 'p' && results [qpd] != 'd' && !isdigit(results[qpd]))
        {
            return false;
        }

    }
    if (tests == passes + defects) {
        return true;
    }
    return false;
}

//return the number of passes
int passQC (string results)
{
    if (isValidQC(results))
    {
        int passNum = 0;
        
        for (int p = 1; p < results.size(); p++)
        {
            if (results [p] == 'p' && isdigit (results [p++]))
            {
                passNum = passNum + results [p++] - '0';
            }
            
        }
        return passNum;
    }
    else
    {
        return -1;
    }
}
    
//return the number of defects
int defectQC (string results)
{
    if (isValidQC(results))
    {
        int defectNum = 0;
            
        for (int d = 0; d < results.size(); d++)
        {
            if (results [d] == 'd' && isdigit (results [d++]))
            {
                defectNum = defectNum + results [d++] - '0';
            }
        }
        return defectNum;
    }
    else
    {
        return -1;
    }
}

//return number of tests
int totalQC (string results)
{
    if (isValidQC(results))
    {
        int testNum = 0;
        
        for (int t = 0; t < results.size(); results [t++])
        {
            if (results [t] == 'Q' && isdigit (results [t++]))
            {
                testNum = testNum + results [t++] - '0';
            }
        }
        return testNum;
    }
    else
    {
        return -1;
    }
}

//return number of batches
int batches (string results)
{
    if (isValidQC(results))
    {
        int batchNum = 0;
        
        for (int b = 0; b < results.size(); results [b++])
        {
            if (results [b] == 'Q')
            {
                batchNum++;
            }
        }
        return batchNum;
    }
    else
    {
        return -1;
    }
}


