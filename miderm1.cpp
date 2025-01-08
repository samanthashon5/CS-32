#include <iostream>
using namespace std;
#include <cassert>
#include<string>

bool somePredicate(string s)
{
    return s.empty();
}

bool allFalse(const string a[],int n)
{
    if (n <= 0)
    {
        return true;
    }

    if(somePredicate(a[0]) == false)
    {
        return allFalse(a + 1, n - 1);
    }
    return false;
}

int countFalse(const string a[], int n)
{
    if(n <= 0)
    {
        return 0;
    }

    if(somePredicate(a[0]) == false)
    {
        int x = 1 + countFalse(a+1, n-1);
    }
    return x;
}

int main() {
    string a[] = { "", "35", "ufwu9fe", "", "bakersfield" };
    assert(!allFalse(a, 4));
    assert(allFalse(a, 0));
    assert(countFalse(a, 3) == 2);
  //  assert(firstFalse(a, 2) == 1);
    string b[] = { "a", "b", "c", "d" };
    assert(allFalse(b, 3));
    assert(countFalse(b, 3) == 3);
   // assert(firstFalse(b, 2) == 0);
    string c[] = { "", "", "" };
   // assert(firstFalse(c, 2) == -1);


    string a1[] = { "a", "b", "c", "d", "c"};
    string a2[] = { "5", "7", "6", "1", "9", "2", "8"};
    string a2b[] = { "", "", "6", "", "9", "", "8" };
    string a3[] = { "A", "C", "", "D", "", "F", "H"};
    string a4[] = { "", "", "", ""};
    string a5[] = { "c", "c"};
    string a6[] = { "", ""};

    assert(allFalse(a1, 5) == true);
    assert(allFalse(a1, 2) == true);
    assert(allFalse(a2, 7) == true);
    assert(allFalse(a3, 7) == false);
    assert(allFalse(a3, 4) == false);
    assert(allFalse(a3, 2) == true);
    assert(allFalse(a4, 1) == false);
    assert(countFalse(a1, 5) == 5);
    assert(countFalse(a3, 7) == 5);
    assert(countFalse(a3, 4) == 3);
    assert(countFalse(a3, 2) == 2);
    assert(countFalse(a6, 2) == 0);

    cerr << "All test cases passed!" << '\n';
    return 0;
}