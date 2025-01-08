#include <iostream>
#include <stack>
#include <cassert>
#include <string>
using namespace std;

int evaluate(string infix, string& postfix, bool& result)
{
    string rinfix;
    //get rid of spaces in infix
    for (int x = 0; x < infix.size(); x++)
    {
        if (infix[x] != ' ')
        {
            if (infix[x] != 'T'  &&  infix[x] != 'F'  &&  infix[x] != '('  &&  infix[x] != ')'  &&  infix[x] != '!'  &&  infix[x] != '&'  &&  infix[x] != '|')
            {
                return 1;
            }
            else
            {
                rinfix += infix[x];
            }
        }
    }

    if (rinfix.size() == 0)
        return 1;

//infix to postfix conversion
    postfix = "";
    stack<char> opstack;
    int ocount = 0;
    int ccount = 0;

    for (int x = 0; x < rinfix.size(); x++)
    {
        char ch = rinfix[x];
        switch (ch)
        {
            case 'T':
            case 'F':
                //only operators should come before an operand
                if (x > 0)
                {
                    if (rinfix[x - 1] == 'T' || rinfix[x - 1] == 'F')
                    {
                        return 1;
                    }
                }
                postfix += ch;
                break;

            case '(':
               //only operators should come before open parentheses
                if (x > 0)
                {
                    if (rinfix[x - 1] == 'T' ||  rinfix[x - 1] == 'F')
                    {
                        return 1;
                    }
                }
                ocount++;
                opstack.push(ch);
                break;
            case ')':
            // must have same amount of open and closed parentheses
                ccount++;
                if(ccount > ocount)
                {
                    return 1;
                }
                //only operands should come before a closed parentheses
                if (rinfix[x - 1] == '('  ||  rinfix[x - 1] == '!'  ||  rinfix[x - 1] == '&'  ||  rinfix[x - 1] == '|')
                {
                    return 1;
                }
                while (opstack.top() != '(')
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.pop();
                break;


            case '!':
                //! cannot be the last character in the string
                if (x == rinfix.size() - 1)
                {
                    return 1;
                }

                while (!opstack.empty()  &&  opstack.top() != '(' &&  opstack.top() != '&'  &&  opstack.top() != '|')
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.push(ch);
                break;

            case '|':
                if (x == rinfix.size() - 1)
                {
                    return 1;
                }
                if (x == 0)
                {
                    return 1;
                }
                if (rinfix[x - 1] == '('  ||  rinfix[x - 1] == '!'  ||  rinfix[x - 1] == '&'  ||  rinfix[x - 1] == '|')
                {
                    return 1;
                }
                while (!opstack.empty()  &&  opstack.top() != '(')
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.push(rinfix[x]);
                break;
            case '&':
                //& must be in between T or F
                if (x == rinfix.size() - 1)
                {
                    return 1;
                }
                if (x == 0)
                {
                    return 1;
                }
                if (rinfix[x - 1] == '(' ||  rinfix[x - 1] == '!'  ||  rinfix[x - 1] == '&'  ||  rinfix[x - 1] == '|')
                    return 1;

                while (!opstack.empty()  &&  opstack.top() != '(' &&  opstack.top() != '|')
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.push(rinfix[x]);
                break;
        }

    }
    if (ocount != ccount)
    {
        return 1;
    }
    while (!opstack.empty())
    {
        postfix += opstack.top();
        opstack.pop();
    }

// postfix evaluation
    for (int x = 0; x < postfix.size(); x++)
    {
        char ch = postfix [x];
        bool operand1;
        bool operand2;
        bool iresult;
        bool operand;
        if (ch == 'T'  ||  ch == 'F')
        {
            opstack.push(ch);
        }
        else if (ch == '!')
        {
            if (opstack.top() == 'T')
            {
                operand = true;
            }
            else if (opstack.top() == 'F')
            {
                operand = false;
            }

            opstack.pop();

            if (operand == true)
            {
                opstack.push('F');
            }
            else
            {
                opstack.push('T');
            }
        }
        else if (ch == '&'  ||  ch == '|')
        {
            if (opstack.top() == 'T')
            {
                operand2 = true;
            }
            else if (opstack.top() == 'F')
            {
                operand2 = false;
            }

            opstack.pop();

            if (opstack.top() == 'T')
            {
                operand1 = true;
            }
            else if (opstack.top() == 'F')
            {
                operand1 = false;
            }

            opstack.pop();

            if (ch == '|')
            {
                iresult = (operand1|operand2);
            }
            else
            {
                iresult = (operand1&operand2);
            }

            if (iresult == true)
            {
                opstack.push('T');
            }
            else
            {
                opstack.push('F');
            }
        }
    }
    bool foperand;
    if (opstack.top() == 'T')
    {
        foperand = true;
    }
    else if (opstack.top() == 'F')
    {
        foperand = false;
    }

    opstack.pop();

    if (opstack.empty())
    {
        if (foperand == true)
        {
            result = true;
            return 0;
        }
        else
        {
            result = false;
            return 0;
        }

    }
    return 1;
}


#include <cassert>
int main()
{
    string pf;
    bool answer;
    assert(evaluate("!!(F|T)", pf, answer) == 0 && pf == "FT|!!" && answer);
    assert(evaluate("T&!F", pf, answer) == 0 && answer);
    assert(evaluate("T|F&F", pf, answer) == 0 && answer);
    assert(evaluate("!F|T", pf, answer) == 0  && answer);
    assert(evaluate("T", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate("T & !(F | T & T | F) | !!!(F & T & F) ", pf, answer) == 0 && answer);
    assert(evaluate("T", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate("F", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("!", pf, answer) == 1);
    assert(evaluate("|", pf, answer) == 1);
    assert(evaluate("&", pf, answer) == 1);
    assert(evaluate("(", pf, answer) == 1);
    assert(evaluate(")", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("A", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate(" !    !!!!!! F  ", pf, answer) == 0);
    assert(evaluate("T|F", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate(" T | F ", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate("T&F", pf, answer) == 0 && pf == "TF&" && !answer);
    assert(evaluate(" T & F ", pf, answer) == 0 && pf == "TF&" && !answer);
    assert(evaluate("!T", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate(" ! T ", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate("(T)", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate(" ( T ) ", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate(" ( T & ! ( F | T & T & ( ! F | F ) ) | F )", pf, answer) == 0 && pf == "TFTT&F!F|&|!&F|" && !answer);
    assert(evaluate(" T ", pf, answer) == 0);
    assert(evaluate(" T &   F    ", pf, answer) == 0 && pf == "TF&" && !answer);
    assert(evaluate("(T&(T&(T&(T&(T&(T&(T&(T&(T)))))))))", pf, answer) == 0 && pf == "TTTTTTTTT&&&&&&&&");
    assert(evaluate(" ", pf, answer) == 1);
    assert(evaluate(" T !", pf, answer) == 1);
    assert(evaluate(" T | &", pf, answer) == 1);
    assert(evaluate(" ( ) ", pf, answer) == 1);
    assert(evaluate(" T ( F & F )", pf, answer) == 1);
    assert(evaluate("T | (F&F|)", pf, answer) == 1);
    assert(evaluate(" T ( & F ) ", pf, answer) == 1);
    assert(evaluate(" F | (T) ) ", pf, answer) == 1);
    assert(evaluate("(((((F)))))", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("T+F", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
        && pf == "FF!TF&&|" && !answer);
    assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("((T))", pf, answer) == 0 && pf == "T" && answer); 
    cout << "Passed all tests" << endl;
} 
