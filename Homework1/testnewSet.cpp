        #include "newSet.h"
        #include <iostream>
        #include <cassert>
        using namespace std;

        void test(const Set& uls)
        {
            assert(uls.size() == 2);
            assert(uls.contains(20));
            ItemType x = 30;
            assert(uls.get(0, x)  &&  x == 20);
            assert(uls.get(1, x)  &&  x == 10);
        }

        int main()
        {
            Set s;
            assert(s.insert(10));
            assert(s.insert(20));
            test(s);
            cout << "Passed all tests" << endl;
        }

