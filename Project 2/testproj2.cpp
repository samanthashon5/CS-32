#include <iostream>
#include <string>
#include <cassert>
#include "Set.h"

using namespace std;

#ifndef TESTNUM
#define TESTNUM 1
#endif

#if TESTNUM == 1
int main() {
   	Set test;
   	assert(test.insert("hi"));
   	assert(test.insert("hey"));
   	assert(test.insert("hiiii"));
   	assert(test.size() == 3);
   	assert(test.contains("hi"));
   	assert(test.contains("hey"));
   	assert(test.contains("hiiii"));
   	assert(!test.empty());
}
//This tests if the insert, contain, size, and empty values do what they’re supposed to
#elif TESTNUM == 2
int main() {
   	Set test;
   	assert(test.insert("hi"));
   	assert(test.insert("hey"));
  	assert(test.insert("hiii"));
   	assert(!test.insert("hi"));
   	assert(test.size() == 3);
   	assert(test.contains("hi"));
   	assert(test.contains("hey"));
   	assert(test.contains("hiii"));
   	assert(!test.empty());
}
//This tests if insert functions properly and doesn’t add a duplicate
#elif TESTNUM == 3
int main()
{
   Set test;
   assert(test.insert("hi"));
   assert(test.insert(""));
   assert(test.insert("heyyy"));
   assert(test.size() == 3);
   Set test2;
   assert(test2.insert("hi"));
   assert(test2.insert("hey"));
   assert(test2.insert("hiii"));
   assert(test2.insert("whatsup"));
   test.swap(test2);
   assert(test.size() == 4);
   assert(test2.size() == 3);
}
//Tests the swap function
#elif TESTNUM == 4
int main() {
   Set test2;
   assert(test2.insert("hi"));
   assert(test2.insert("hii"));
   assert(test2.insert("hey"));
   ItemType x = "";
   for (int i = 0; i < test2.size(); i++) {
       test2.get(i, x);
       cerr << x << '\n';
   }
   test2.get(2, x);
   cerr << x;
   test2.get(0, x);
   cerr << x;
}
//Tests the get function
#elif TESTNUM == 5
int main() 
{
   Set test;
   assert(test.insert("hey"));
   assert(test.insert("hi"));
   assert(test.insert("hii"));
   assert(test.erase("hi"));
   assert(!test.erase("whatsup"));
   assert(test.size() == 2);
}
//Tests the erase function and if a value doesn’t exist, don’t erase
#elif TESTNUM == 6
int main() 
{
   Set test;
   assert(test.insert("hi"));
   assert(test.insert("hey"));
   assert(test.insert("hii"));
   assert(test.erase("hi"));
   assert(test.erase("hey"));
   assert(test.erase("hii"));
   assert(!test.erase(""));
   assert(test.size() == 0);

}
//Tests the size function when we use the erase function to delete everything
#elif TESTNUM ==7
int main() 
{
   Set test;
   assert(test.insert("heyyy"));
   assert(test.insert("whatsup"));
   Set test2(test);
   for (int i = 0; i < test2.size(); i++) {
       ItemType x = "";
       test2.get(i, x);
       cerr << x << '\n';
   }
}
//Tests the copy constructor
#elif TESTNUM == 8
int main() 
{
   Set test;
   assert(test.insert("Hiiii"));
   assert(test.insert("hey"));
   Set test2;
   test2 = test;
   for (int i = 0; i < test2.size(); i++) {
       ItemType x = "";
       test2.get(i, x);
       cerr << x << '\n';
    }
}
//Tests the assignment operator
#elif TESTNUM == 9
int main(){
   Set test;
   assert(test.insert("hi"));
   assert(test.insert("hii"));
   assert(test.insert("hey"));
   Set test2;
   assert(test2.insert("hii"));
   assert(test2.insert("hey"));
   assert(test2.insert("hello"));

   Set x;
   unite(test, test2, x);
   for (int i = 0; i < x.size(); i++) {
       ItemType y = "";
       x.get(i, y);
       cerr << y << '\n';
   }

}
//Tests the unite function
#elif TESTNUM == 10
int main()
{
	Set test;
   assert(test.insert("hi"));
   assert(test.insert("hii"));
   assert(test.insert("hey"));
   Set test2;
   assert(test2.insert("hii"));
   assert(test2.insert("hey"));
   assert(test2.insert("hello"));

   Set y;
   cerr << '\n';
   inOnlyOne(test, test2, y);
   for (int i = 0; i < y.size(); i++) {
       ItemType x = "";
       y.get(i, x);
       cerr << x << '\n';
	}
}
//Tests the inOnlyOne function
#elif TESTNUM == 11
int main() 
{
   Set test;
   assert(test.insert("a"));
   assert(test.insert("b"));
   assert(test.insert("c"));
   Set two;
   assert(two.insert("b"));
   assert(two.insert("c"));
   assert(two.insert("d"));
   //should print "d, b, c, a" and "a"
   unite(test, two, test);
   for (int i = 0; i < test.size(); i++) {
       ItemType dummy = "";
       test.get(i, dummy);
       cerr << dummy << '\n';
   }
   cerr << '\n';
   inOnlyOne(test, two, two);
   for (int i = 0; i < two.size(); i++) {
       ItemType dummy = "";
       two.get(i, dummy);
       cerr << dummy << '\n';
   }
}
//Tests when the function has the same element twice (from discord @easypeasy123)
#elif TESTNUM == 12
int main() 
{
   Set test;
   for (int i = 0; i < 100; i += 2) {
       assert(test.insert(i));
   }
   Set test2;
   for (int i = 0; i < 100; i += 3) {
       assert(test2.insert(i));
   }
   assert(test.size() == 50);
   assert(test2.size() == 34);
   Set x;
   unite(test, test2, x);
   assert(x.size() == 67);
   Set y;
   inOnlyOne(test, test2, y);
   assert(x.size() == 50);
}
//Tests that aliasing worked (unsigned long)(from discord @easypeasy123)
#endif