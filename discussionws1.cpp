#include <iostream>
using namespace std;

class A{
    public:
        A(int sz)
        {
            b = new B;
            arr = new int[sz];
            n = sz;
        }

        A(const A& other)
        {
            b = new B(* other.b);
            n = other.n;
            str = other.str;
            for (int i = 0; i < n; i++)
            {
                arr[i] = other.arr[i];
            }
        }

        A& operator=(const A& other)
        {
            if (this != &other)
            {
                A temp(other);
                swap(b.temp.b);
                swap(arr.temp.arr);
                swap(n.temp.n);
                swap(str.temp.str);
            }
            return *this;
        }

        ~A()
        {
            delete b;
            delete[] arr;
        }
    private:
        B* b;
        int* arr;
        int n;
        string str;
}