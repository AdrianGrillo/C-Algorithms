#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force in O(nlogn) time and O(nlogn) space
vector<int> subarraySort(vector<int> a)
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

// O(n) time

// Helper function to tell us whether or not the element is out of order and handle edge cases
bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];

    // If the first element is out of order
    if (i == 0)
    {
        return x > arr[1];
    }

    // If the last element is out of order
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }

    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subarraySort(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int n = arr.size();

    // If the current index is greater than the next index, the next index is out of order. If it's out of order then update our largest and smallest variables with those values
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];

        if (outOfOrder(arr, i))
        {
            largest = max(largest, x);
            smallest = min(smallest, x);
        }
        i++;
    }

    // Find the right index where the smallest and largest lie
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }

    int right = n - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    return {left, right};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout << p.first << " and " << p.second << endl;

    return 0;
}