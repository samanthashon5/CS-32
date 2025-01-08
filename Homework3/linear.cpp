//DELETE THE INCLUDE DIRECTIVES WHEN DONE
  
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
