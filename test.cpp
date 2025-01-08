#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "john" "amy" "ketanji" "sonia" "amy" "ketanji" "elena"
// then for this value of a2            the function must return
//    "john" "sonia" "ketanji"                      1
//    "john" "ketanji" "elena"                      2
//    "sonia" "john" "ketanji"                      0
//    "amy" "ketanji" "elena"                       3
int numberOfTimesHas(const string a1[], int n1, const string a2[], int n2)
{
  if(n2 == 0)
  {
    return 1;
  }

  if(n1 < n2)
  {
    return 0;
  }

//If any of the parameters n1, n2, or n is negative, act as if it were zero.
  if(n1 < 0)
  {
    n1 = 0;
  }
  if(n2 < 0)
  {
    n2 = 0;
  }

  if(a2[0] == a1[0])
  {
    //move on to the next element of each array
    int x = numberOfTimesHas(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
    //check to see if the string in a2 is repeated
    int y = numberOfTimesHas(a1 + 1, n1 - 1, a2, n2);
    return x + y;
  }
  return numberOfTimesHas(a1 + 1, n1 - 1, a2, n2);
}

int main()
{
    string arra[] = {"john", "amy", "ketanji", "sonia", "amy", "ketanji", "elena"};
    string arrb[] = {"john", "sonia", "ketanji"};
    assert(numberOfTimesHas(arra,  7, arrb, 3) == 1);
    arrb[1] = "ketanji";
    arrb[2] = "elena"; //    "john" "ketanji" "elena"
    assert(numberOfTimesHas(arra,  7, arrb, 3) == 2);
    string arrc[] = {"sonia", "john", "ketanji"};
    assert(numberOfTimesHas(arra,  7, arrc, 3) == 0);
    string arrd[] = {"amy", "ketanji", "sonia"};
    assert(numberOfTimesHas(arra, 7, arrd, 2) == 3);
    assert(numberOfTimesHas(arra,  7, arrd, 3) == 1);
    string arre[] = {"kentaji", "ketanji", "kentaji"};
    assert(numberOfTimesHas(arra,  7, arre, 3) == 0);
    string arrf[] = {"john", "amy", "ketanji"};
    assert(numberOfTimesHas(arra,  7, arrf, 3) == 3);
    assert(numberOfTimesHas(arra,  5, arrf, 3) == 1);
    assert(numberOfTimesHas(arra, 2, arrf, 2) == 1);
    assert(numberOfTimesHas(arra, 7, arrf, 2) == 2);
    assert(numberOfTimesHas(arra, 7, arrf, -1) == 1);
    string arrg[] = {"john", "amy", "ketanji", "sonia", "amy", "ketanji", "elena"};
    assert(numberOfTimesHas(arra, 7, arrg, 7) == 1);
    assert(numberOfTimesHas(arra, 7, arrg, 3) == 3);
    assert(numberOfTimesHas(arra, 0, arrg, 0) == 1);
    assert(numberOfTimesHas(arra, 7, arrg, 0) == 1);
    string arrh[] = {}; //might not work depending on compiler
    assert(numberOfTimesHas(arra, 7, arrh, 0) == 1);
    assert(numberOfTimesHas(arra, 0, arrh, 0) == 1);
    assert(numberOfTimesHas(arra, 0, arrh, 3) == 0);
}