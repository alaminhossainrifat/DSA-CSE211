#include <iostream>
using namespace std;

int main() {
    int n, left, right, mid, data;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> data; // Read the element to search for

    left = 0;
    right = n - 1;

    while(left <= right) {
        mid = left + (right - left) / 2;
        if(data == arr[mid]) {
            cout << "Element found at index: " << mid << endl;
            return 0; // Element found
        }
        else if(data > arr[mid]) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}