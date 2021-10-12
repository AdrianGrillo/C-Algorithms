#include <iostream>
#include <vector>
using namespace std;

int rains(vector<int> heights)
{
    int n = heights.size();
    int water = 0;

    // If there are only two buildings, no water will be trapped
    if (n <= 2)
    {
        return 0;
    }

    // Initialize two vectors with n indexes of 0 then assign the first and last elements of the given array to each respectively
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    // Precompute the height of each building, continue to store the largest height found for each index in the array
    // Left will start at the beginning and work forward while right will start at the end and work towards the beginning
    for (int i = 1; i <= n - 1; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    // Compute water being stored
    for (int i = 0; i <= n - 1; i++)
    {
        water += min(left[i], right[i]) - heights[i];
    }

    return water;
}

int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << rains(heights) << endl;

    return 0;
}