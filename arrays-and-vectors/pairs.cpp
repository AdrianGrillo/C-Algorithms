#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum)
{

    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        // x is the second value in the pair
        int x = Sum - arr[i];

        // s.find() will return an iterator pointing to s.end() if the item isn't found in the set. So if s.find() != s.end() then the item must not be in our set and we can then add it and look at the next  index in the array.
        if (s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        else
        {
            s.insert(arr[i]);
        }
    }

    return {};
}

int main()
{

    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int Sum = 4;

    auto p = pairSum(arr, Sum);
    if (p.size() == 0)
    {
        cout << "No such pair";
    }
    else
    {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}

// On my own

/* 
The brute force approach would be to initialize 2 for loops. One would iterate through the given array and at each index, the other would iterate through the rest of the indexes to look for the other integer in the pair. This would give us O(n^2) time. 

A better approach is to sort the array and apply a binary search which would give O(nlogn) time.

The best approach to this algorithm by utilizing a data structure. An unordered set would allow us to store all of the integers in the input array and access them in O(1) time. We can then use a single for loop to check if the other integer in the pair exists in our set. If it doesn't, then store that index in the set and continue to the next index. Do this until our second integer in the pair is found in the set. This yields O(n) time. 
 */

vector<int> pairSum(vector<int> arr, int Sum)
{
    unordered_set<int> set;
    int n = arr.size();
    vector<int> pair;

    for (int i = 0; i < n; i++)
    {
        // x is the second integer in the pair
        int x = Sum - arr[i];

        // If x is found in our set, else if it isnt
        if (set.find(x) != set.end())
        {
            pair.push_back(arr[i]);
            pair.push_back(x);
            return pair;
        }
        else
        {
            set.insert(arr[i]);
        }
    }

    return {};
}

int main()
{

    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int Sum = 4;

    auto p = pairSum(arr, Sum);
    if (p.size() == 0)
    {
        cout << "No such pair";
    }
    else
    {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}