#include <iostream>
using namespace std;

int main() {
    int n, data;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> data; // Read the element to search for

    int pos = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == data) {
            pos = i;
            break;
        }
    }
    if (pos == -1)  {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index: " << pos << endl;
    }
    return 0; 
}