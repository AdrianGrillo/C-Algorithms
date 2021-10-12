#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force in O(nlogn) time and O(nlogn) space
vector<int> subarray_sort(vector<int> a)
{
    // Create a copy of the input array that isn't sorted
    vector<int> b(a);
    sort(a.begin(), a.end());
    int n = a.size();
    int i = 0;
    int j = n - 1;

    // Iterate from left while indexe values are equal
    while (i < n and a[i] == b[i])
    {
        i++;
    }

    // Iterate from right while index values are equal
    while (j >= 0 and a[j] == b[j])
    {
        j--;
    }

    if (i == n)
    {
        return {-1, -1};
    }

    return {i, j};
}