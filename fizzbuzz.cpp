#include <bits/stdc++.h>
using namespace std;

// solution function

vector<string> fizzBuzz(int n)
{
    // vector to store solution
    vector<string> solution;

    //for all n

    for (int i = 1; i <= n; i++)
    {
        // if div by 15
        if (i >= 15 && i % 15 == 0)
        {
            solution.push_back("FizzBuzz");
        }
        // if div by 15
        else if (i >= 5 && i % 5 == 0)
        {
            solution.push_back("Buzz");
        }
        else if (i >= 3 && i % 3 == 0)
        {
            solution.push_back("Fizz");
        }
        else
        {
            solution.push_back(to_string(i));
        }
    }

    return solution;
}

// main function
int main()
{

    vector<string> ans1 = fizzBuzz(5);
    vector<string> ans2 = fizzBuzz(15);

    for (auto itr : ans1)
    {
        cout << itr << endl;
    }

    cout << "answer2 " << endl;
    for (auto itr : ans2)
    {
        cout << itr << endl;
    }

    return 0;
}