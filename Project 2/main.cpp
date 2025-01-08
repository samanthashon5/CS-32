#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

// Test Cases: 
//
// using ItemType = std::string
// 
// 1. default constructor
// 2. insert function
// 3. erase function
// 4. get function 
// 5. swap function
// 6. copy constructor
// 7. assignment operator
// 8. unite function
// 9. inonlyone function
// Any other number: a general test case which tests a bunch of stuff




#ifndef TESTNUM
#define TESTNUM 9. // CHANGE TEST CASE HERE
#endif

#if TESTNUM == 1
// Testing the default constructor

	int main() {
		Set a;
		string x;
		assert(a.size() == 0);
		assert(a.empty());
		assert(!a.get(0, x));


		cout << "test case 1 passed" << endl;

	}

#elif TESTNUM == 2
// Testing the insert function

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.insert("zzz"));
		assert(a.size() == 5);


		assert(!a.insert("test"));
		string x = "hi";
		assert(!a.insert(x));
		assert(a.size() == 5);

		assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("") && a.contains("zzz"));

		cout << "test case 2 passed" << endl;

	}


#elif TESTNUM == 3
// Testing the erase function

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);


		assert(a.erase("hi"));
		assert(a.size() == 3);
		assert(!a.erase("hi"));
		assert(a.size() == 3);
		assert(a.erase("aa"));
		assert(a.erase(""));
		assert(a.erase("test"));
		assert(a.size() == 0);
		assert(a.empty());
		assert(!a.erase(""));
		
		assert(!a.contains("hi") && !a.contains("test") && !a.contains("aa") && !a.contains(""));


		cout << "test case 3 passed" << endl;

	}


#elif TESTNUM == 4
// Testing the get function

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);

		string x;
		assert(a.get(0, x) && x == "test");
		assert(a.get(1, x) && x == "hi");
		assert(a.get(2, x) && x == "aa");
		assert(a.get(3, x) && x == "");
		assert(!a.get(4, x) && x == "");
		assert(a.size() == 4);


		assert(a.insert("zzz"));
		assert(a.get(0, x) && x == "zzz");
		assert(a.get(4, x) && x == "");
		assert(!a.get(-10, x) && x == "");
		assert(a.size() == 5);

		assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("") && a.contains("zzz"));

		cout << "test caase 4 passed" << endl;

	}



#elif TESTNUM == 5
// Testing the swap function

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);

		
		Set b;
		assert(b.insert("math"));
		assert(b.insert("physics"));
		assert(b.insert("aa"));

		a.swap(b);

		assert(a.size() == 3 && b.size() == 4);
		assert(a.contains("math") && a.contains("aa") && a.contains("physics"));
		assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains(""));


		Set c;
		b.swap(c);
		assert(b.size() == 0 && c.size() == 4);
		assert(!b.contains("hi") && !b.contains("test") && !b.contains("aa") && !b.contains(""));
		assert(c.contains("hi") && c.contains("test") && c.contains("aa") && c.contains(""));


		Set d;
		d.swap(b);
		assert(b.size() == 0 && d.size() == 0);
	


		cout << "test case 5 passed" << endl;

	}




#elif TESTNUM == 6
// Testing the copy constructor

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);


		Set b(a);
		assert(a.size() == 4 && b.size() == 4);
		assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains(""));
		assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains(""));

		Set c;
		c.insert("car");
		c.insert("helicopter");
		Set d(c);
		assert(c.size() == 2 && d.size() == 2);
		c.erase("car");
		d.insert("bicycle");
		assert(c.size() == 1 && d.size() == 3);

		Set e;
		Set f(e);
		assert(f.size() == 0 && e.size() == 0);




		cout << "test case 6 passed" << endl;

	}






#elif TESTNUM == 7
// Testing the assignment operator

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);


		Set b;
		b = a;

		assert(a.size() == 4 && b.size() == 4);
		assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains(""));
		assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains(""));

		Set c;
		b = c;
		assert(b.size() == 0 && c.size() == 0);
		assert(!b.contains("hi") && !b.contains("test") && !b.contains("aa") && !b.contains(""));
		assert(!c.contains("hi") && !c.contains("test") && !c.contains("aa") && !c.contains(""));

		Set d;
		d = c;
		assert(d.size() == 0 && c.size() == 0);




		cout << "test case 7 passed" << endl;

	}

#elif TESTNUM == 8
// Testing the unite function


	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);


		Set b;
		assert(b.insert("math"));
		assert(b.insert("physics"));
		assert(b.insert("aa"));

		Set c;
		unite(a, b, c);
		assert(a.size() == 4 && b.size() == 3 && c.size() == 6);
		assert(c.contains("hi") && c.contains("test") && c.contains("aa") && c.contains("") && c.contains("math") && c.contains("physics"));

		Set d;
		assert(d.insert("red"));
		assert(d.insert("blue"));
		assert(d.insert("green"));
		unite(a, b, d);
		assert(a.size() == 4 && b.size() == 3 && d.size() == 6);
		assert(d.contains("hi") && d.contains("test") && d.contains("aa") && d.contains("") && d.contains("math") && d.contains("physics"));


		Set e;
		assert(e.insert("dog"));
		unite(d, e, d);
		assert(d.size() == 7 && e.size() == 1);
		assert(d.contains("hi") && d.contains("test") && d.contains("aa") && d.contains("") && d.contains("math") && d.contains("physics") && d.contains("dog"));


		Set f;
		unite(f, e, f);
		assert(f.size() == 1 && f.contains("dog"));

		Set g(f);
		unite(g, f, g);
		assert(g.size() == 1 && g.contains("dog"));




		cout << "test case 8 passed" << endl;

	}




#elif TESTNUM == 9
// Testing the inonlyone function

	int main() {
		Set a;
		assert(a.insert("hi"));
		assert(a.insert("test"));
		assert(a.insert(""));
		assert(a.insert("aa"));
		assert(a.size() == 4);


		Set b;
		assert(b.insert("math"));
		assert(b.insert("physics"));
		assert(b.insert("aa"));

		Set c;
		inOnlyOne(a, b, c);
		assert(a.size() == 4 && b.size() == 3 && c.size() == 5);
		assert(c.contains("hi") && c.contains("test") && c.contains("") && c.contains("math") && c.contains("physics"));

		Set d;
		Set e;
		inOnlyOne(a, d, e);
		for (int i = 0; i < a.size(); i++) {
			string x;
			a.get(i, x);
			assert(e.contains(x));
		}

		inOnlyOne(a, d, a);
		assert(a.contains("hi") && a.contains("test") && a.contains("") && a.contains("aa"));




		cout << "test case 9 passed" << endl;

	}


#else
// A test case with a bunch of stuff


int main()
{

	Set a;

	assert(a.size() == 0);
	assert(a.insert("hi"));
	assert(a.size() == 1);
	assert(!a.insert("hi"));
	assert(a.size() == 1);


	assert(a.insert("test"));
	assert(a.insert("tony"));
	assert(a.size() == 3);
	assert(!a.insert("tony"));
	assert(a.insert("b"));
	assert(a.insert("Aaaaaaa"));
	assert(a.insert("smallberg"));
	assert(a.size() == 6);
	

	assert(a.erase("tony"));
	assert(!a.erase("david"));
	assert(a.erase("hi"));
	assert(a.size() == 4);

	string x;
	assert(a.get(3, x) && x == "Aaaaaaa");
	assert(!a.get(6, x) && x == "Aaaaaaa");
	assert(a.get(0, x) && x == "test");


	Set b(a);


	assert(b.size() == 4);
	assert(b.get(0, x) && x == "test");
	assert(b.erase("Aaaaaaa"));


	assert(b.size() == 3);
	assert(b.get(0, x));

	Set c;
	assert(c.insert(""));
	assert(c.get(0, x) && x == "");
	c.swap(a);
	assert(a.size() == 1);
	assert(a.get(0, x) && x == "");



	

	cout << "all tests passed" << endl;


}
 

#endif
