#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int Sum)
{
    vector<vector<int>> result;
    int n = arr.size();

    // Sort array so we can use two pointer approach
    sort(arr.begin(), arr.end());

    // Pick every a[i], find the pair for remaining indexes
    for (int i = 0; i <= n - 3; i++)
    {

        // j starts at the index after the current a[i]
        int j = i + 1;
        // k starts at the last element in the array
        int k = n - 1;

        // Two pointer approach
        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == Sum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > Sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int Sum = 18;

    auto result = triplets(arr, Sum);

    for (auto v : result)
    {
        for (auto no : v)
        {
            cout << no << ",";
        }
        cout << endl;
    }

    return 0;
}

/* 
Brute force approach: Three for loops. One to iterate through the sorted array to find each triplet individually, this will yeild O(n^3) time. 

A better approach: Have a for loop iterate through each index in the input array and then for each index, have another for loop perform the pairs algorithm. Since the pairs algorithm with the unordered set gives O(n) time, this will give us a total time complexity of O(n^2) and space complexity of the same. 

The best approach: Use a for loop to iterate through the input array and at each index, use the two pointer method to find the other two values in our triplet. This would yeild O(n^2) time with only O(n) space complexity. 
*/

vector<vector<int>> triplets(vector<int> arr, int Sum)
{
    vector<vector<int>> result;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            // If integers at j and k indexes add up to pair, push them into the result vector
            if (current_sum == Sum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                // If a triplet is found, increment and decrement each pointer respectively
                j++;
                k--;
            }
            else if (current_sum > Sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int Sum = 18;

    auto result = triplets(arr, Sum);

    for (auto v : result)
    {
        for (auto no : v)
        {
            cout << no << ",";
        }
        cout << endl;
    }

    return 0;
}