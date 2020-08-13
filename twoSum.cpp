#include <bits/stdc++.h>

using namespace std;

vector<int> answer(vector<int> &nums, int target)
{
    // for each element in vector array, check if the number exists in hashmap
    // then return, else update hashmap < difference , index >

    // declare hashmap
    unordered_map<int, int> smap;

    for (int i = 0; i < nums.size(); i++)
    {
        // check if the number is a difference already stored in hashmap
        // check if element exists as a key in smap
        auto itr = smap.find(nums[i]);

        // if not found, itr will point to end
        if (itr != smap.end())
        {
            //key found
            vector<int> solution = {itr->second, i};
            // found existing
            return solution;
        }

        // if not exists, update the hashmap

        smap[target - nums[i]] = i;
    }

    // solution not found
    vector<int> result = {-1};
    return result;
}

int main()
{
    vector<int> vec = {1, 32, 354, 22, 12, 29};
    int target = 30;

    vector<int> result = answer(vec, target);

    for (auto itr : result)
    {

        cout << itr << endl;
    }

    return 0;
}