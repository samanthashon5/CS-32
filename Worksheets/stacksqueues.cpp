#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

bool isValid(string symbols)
{
    stack <char> istack;
    for(int i = 0; i < symbols.size(); i++)
    {
        char c = symbols[i];
        switch (c)
        {
            case '(':
            case '[':
                istack.push(c);
                break;
            case ')':
                if(istack.empty || istack.top() != '(')
                {
                    return false;
                }
                else{
                    istack.pop();
                }
                break;
            case ']':
                if(istack.empty() || istack.top() != '[')
                {
                    return false:
                }
                else{
                    istack.pop();
                }
                break;
        }
    }
    return istack.empty();
}


void reverseQueue(queue<int>& Q)
{
    stack <int> S
    while(!Q.empty())
    {
        S.push(Q.front());
        Q.pop()
    }
    while(!S.empty())
    {
        Q.push(S.top());
        S.pop();
    }
}


void findNextInts(const int sequence[], int results[], int n)
{
    if(n == 0)
    {
        return -1;
    }

    stack<int> istack;

    istack.push(0);

    for(int i = 1; i < n; i++)
    {
        int curr = sequence[i];
    }

    while(!istack.empty() && curr > sequence[istack.top()])
    {
        results[istack.top()] = curr;
        istack.pop();
    }

    istack.push(i);

    while(!istack.empty())
    {
        results[istack.top()] = -1;
        istack.pop();
    }
}


class Stack
{
    public:
     Stack();
     void push(int i);
     {
        
     }
     int pop();
     bool empty();
     int size();
     int top();

    private:
     queue<int> Q;

}