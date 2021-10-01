#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Demo Vector
    vector<int> arr = {1, 2, 12, 15};

    // Pop_back will remove an element at athe end of the array
    arr.pop_back();

    // Push_back: This will insert an element at the end of the array
    arr.push_back(16);

    // Fill Constructor will fill a number of indexes with a specific value, in this case, 7
    vector<int> arr(10, 7);

    // Print all elements
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    // Print all elements with a for each loop. For every index x in the array, print it followed by a comma
    for (int x : arr)
    {
        cout << x << ",";
    }

    // Number of items in the vector
    cout << arr.size() << endl;

    // Number of indexes in vector (including empty ones)
    cout << arr.capacity() << endl;

    return 0;
}