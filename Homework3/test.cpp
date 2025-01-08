//DELETE THE INCLUDE DIRECTIVES WHEN DONE
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool somePredicate(string s)
{
  return s.empty();
}
  
// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool allFalse(const string a[], int n)
{
  //if n1, n2, or n is negative, assume they are equal to 0
  if(n < 0)
  {
    n = 0;
  }

  //base case
  if(n == 0)
  {
    return true;
  }

  if(somePredicate(a[0]) == false)
  {
    return allFalse(a + 1, n - 1);
  }

  return false;
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
  //if n1, n2, or n is negative, assume they are equal to 0
  if(n < 0)
  {
    n = 0;
  }
  
  //base case
  if(n == 0)
  {
    return 0;
  }

  int x = 0;
  int y = 0;
  if(somePredicate(a[0]) == false)
  {
    x++;
  }
  y = countFalse(a + 1, n - 1);

  return x + y;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
  //if n1, n2, or n is negative, assume they are equal to 0
  if(n < 0)
  {
    n = 0;
  }
  
  //base case
  if(n == 0)
  {
    return -1;
  }
          
  if(somePredicate(a[0]) == false)
  {
    return 0;
  }

  int f = firstFalse(a + 1, n - 1);
  if (f != -1)
  {
    return f + 1;
  }

  return -1;
}

// Return the subscript of the greatest string in the array (i.e.,
// return the smallest subscript m such that a[m] >= a[k] for all
// k from 0 to n-1).  If the function is told that no strings are to
// be considered to be in the array, return -1.
int indexOfMax(const string a[], int n)
{
  //if n1, n2, or n is negative, assume they are equal to 0
  if(n < 0)
  {
    n = 0;
  }
  
  //base case
  if(n == 0)
  {
    return -1;
  }

  if(n == 1)
  {
    return 0;
  }

  int i = indexOfMax(a + 1, n - 1);

  if(a[0] >= a[i + 1])
  {
    return 0;
  }

  return i + 1;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "john" "amy" "ketanji" "sonia" "amy" "ketanji" "elena"
// then the function should return true if a2 is
//    "amy" "sonia" "elena"
// or
//    "amy" "ketanji" "ketanji"
// and it should return false if a2 is
//    "amy" "elena" "sonia"
// or
//    "john" "sonia" "sonia"
bool has(const string a1[], int n1, const string a2[], int n2)
{
  //if n1, n2, or n is negative, assume they are equal to 0
  if(n1 < 0)
  {
    n1 = 0;
  }
  if(n2 < 0)
  {
    n2 = 0;
  }

  //base case
  if(n2 == 0)
  {
    return true;
  }

  if(n1 == 0)
  {
    return false;
  }

  if(a2[0] == a1[0])
  {
    return has(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
  }

  return has(a1 + 1, n1 - 1, a2, n2);
}


int main()
{
  string a[6] = { "john", "amy", "ketanji", "sonia", "amy", "ketanji" };
  string a2[3] = { "amy", "sonia", "elena" };
  string a3[3] = { "amy", "ketanji", "ketanji" };
  string a4[3] = { "amy", "elena", "sonia" };
  string a5[3] = { "john", "sonia", "sonia" };

  string b[3] = { "amy", "sonia", "elena" };
  string b2[4] = { "amy", "sonia", "elena", ""};
  string c[4] = { "", "", "", "" };
  string d[6] = { "", "", "", "", "john", "amy", };


  assert(allFalse(a, 6) == true);
  assert(allFalse(b, 3) == true);
  assert(allFalse(c, 4) == false);

  assert(countFalse(a, 6) == 6);
  assert(countFalse(b, 3) == 3);
  assert(countFalse(c, 4) == 0);

  assert(firstFalse(a, 6) == 0);
  assert(firstFalse(b, 3) == 0);
  assert(firstFalse(c, 4) == -1);
  assert(firstFalse(d, 6) == 4);

  assert(indexOfMax(a, 6) == 3);
  assert(indexOfMax(a, 2) == 0);
  assert(indexOfMax(b, 0) == -1);
  assert(indexOfMax(b, 3) == 1);
  assert(indexOfMax(c, 4) == 0);
  assert(indexOfMax(d, 6) == 4);
  assert(indexOfMax(d, 4) == 0);

  assert(has(a, 7, a2, 3) == false);
  assert(has(a, 7, a3, 3) == true);
  assert(has(a, 3, a3, 3) == false);
  assert(has(a, 7, a4, 3) == false);
  assert(has(a, 7, a5, 3) == false);
  assert(has(a, 1, a2, -2) == true);

  cerr << "all tests PASSED" << endl;
}