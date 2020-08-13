#include <bits/stdc++.h>
using namespace std;

// solution function

bool containsDuplicate(vector<int> &nums)
{
    // O(n) using hashmaps

    unordered_map<int, int> smap;

    for (auto itr : nums)
    {
        //check if the number already exists in the hashmap
        if (smap.find(itr) != smap.end())
        {
            //duplicate exists
            return true;
        }
        else
        {
            //set value as 1 if exists
            smap[itr] = 1;
        }
    }
    //no repeatation found
    return false;
}

//main function

int main()
{
    vector<int> v1 = {1, 2, 3, 1}; // same - returns true
    vector<int> v2 = {1, 4, 6, 9}; // all -  different returns false

    cout << containsDuplicate(v1) << endl;
    cout << containsDuplicate(v2) << endl;
    return 0;
}
