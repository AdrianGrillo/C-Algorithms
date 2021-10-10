#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longest_band(vector<int> arr)
{
    unordered_set<int> s;
    int n = arr.size();
    int longestBand = 1;

    for (int x : arr)
    {
        s.insert(x);
    }

    for (auto element : s)
    {
        // Parent variable will allow us to check if an integer is the first digit in a band
        int parent = element - 1;

        // Only start a band if an integers parent doesn't exist in the set
        if (s.find(parent) == s.end())
        {
            int next_no = element + 1;
            int count = 1;

            // Find entire band starting at element, increment next_no after each iteration so it will change with our loop
            while (s.find(next_no) != s.end())
            {
                next_no++;
                count++;
            }

            if (count > longestBand)
            {
                longestBand = count;
            }
        }
    }

    return longestBand;
}

int main()
{
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << longest_band(arr) << endl;

    return 0;
}