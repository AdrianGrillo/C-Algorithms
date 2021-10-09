#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int highest_mountain(vector<int> arr)
{
    int n = arr.size();
    int largest = 0;

    // Starting from the second element and stopping at the second to last element because the first and last elements cannot be peaks

    // Another small thing: the loop isn't being incremented in the for conditoinal, we only increment at the end after our if statement inside has checked if there's a peak or not.
    for (int i = 1; i <= n - 2;)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            int count = 1;
            int j = i;

            // Count backwards (left) only when j > the previous element
            while (j >= 1 and arr[j] > arr[j - 1])
            {
                j--;
                count++;
            }
            // Count forwards (right) only when i > the next element
            while (i <= n - 2 and arr[i] > arr[i + 1])
            {
                i++;
                count++;
            }

            largest = max(largest, count);
        }
        else
        {
            i++;
        }
    }

    return largest;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

    cout << highest_mountain(arr) << endl;

    return 0;
}