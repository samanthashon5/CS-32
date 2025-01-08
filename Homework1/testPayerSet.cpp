        #include "PayerSet.h"
        #include <iostream>
        #include <cassert>
        using namespace std;

        int main()
        {
            PayerSet s;
            assert(s.add(1043056));
            assert(s.add(12345));
            assert(s.add(12356767));
            assert(s.size());
            (s.print());
            cout << "Passed all tests" << endl;
        }