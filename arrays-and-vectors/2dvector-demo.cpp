#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 2D Vector where each index is a vector and each index can have a different number of elements
    vector<vector<int>> arr = {
        {1, 2, 3},
        {3, 4, 6},
        {7, 8, 9, 10},
        {11, 12}};

    // Increment first element of first vector by 10
    arr[0][0] += 10;

    // For each vector in the 2d vector, print each interger inside followed by a comma
    for (int i = 0; i < arr.size(); i++)
    {

        for (int number : arr[i])
        {
            cout << number << ",";
        }
        cout << endl;
    }

    return 0;
}