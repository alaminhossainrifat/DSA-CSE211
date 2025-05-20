#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st , j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {  //Accending order(<=) || //Descending order(>=)
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx=0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    } 
}


void mergeSort(vector<int>& arr, int st, int end) {
    if (st >= end) return; 

    int mid = st + (end - st) / 2; // calculate mid

    mergeSort(arr, st, mid); // Sort the left half
    mergeSort(arr, mid + 1, end); // Sort the right half

    merge(arr, st, mid, end); // Merge the sorted halves
}


int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    mergeSort(arr, 0, arr.size() - 1);

    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
