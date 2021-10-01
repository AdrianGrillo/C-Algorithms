#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Demo Vector
    vector<int> arr = {1, 2, 12, 15};

    // Push_Back
    arr.push_back(16);

    // Print all elements
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    // // Number of items in the vector
    // cout << arr.size() << endl;

    // // Number of indexes in vector (including empty ones)
    // cout << arr.capacity << endl;

    return 0;
}