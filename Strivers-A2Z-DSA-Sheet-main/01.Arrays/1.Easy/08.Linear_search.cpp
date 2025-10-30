

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4; // element to search

    bool found = false;

    // Linear search logic
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
