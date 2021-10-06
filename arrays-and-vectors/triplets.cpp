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
                result.push_back({arr[i], arr[j], arr[j]});
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