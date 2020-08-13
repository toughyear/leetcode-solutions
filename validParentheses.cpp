#include <bits/stdc++.h>

using namespace std;

// creating the solution function

bool isValid(string s)
{

    // need a stack
    stack<char> st;

    // loop for each character in s

    for (int i = 0; i < s.size(); i++)
    {
        //single quote because characters not string
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            //opening brackets, push to stack
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                //stack empty cant remove
                return false;
            }

            switch (s[i])
            {
            case '}':
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ')':
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            }
        }
    }

    // all checked now, hopefully stack must be empty by now.
    // if string is empty, stack should still be empty

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// call from the main function

int main()
{

    string s1 = "{}[](())";  //valid
    string s2 = "{}[](())]"; //invalid

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;

    return 0;
}