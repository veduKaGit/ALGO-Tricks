// Time Complexity: 
// O(n*logn) avergae
// O(n^2) worst case => Occurs when the smallest or largest element is always chosen as the pivot


// Algo:
// 1. Choose a Pivot: Select an element from the array as the pivot. 
//    For simplicity, we chose the last element. We can chose any random element otherwise.
// 2. Partition the Array: Rearrange the array around the pivot. 
//    After partitioning, all elements smaller than the pivot will be on its left, 
//    and all elements greater than the pivot will be on its right. 
// 3. Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).

// Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  //last element as pivot
  
    // Elements from low to i are smaller than pivot
    int i = low - 1;  //IMP => (low-1)

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements
    swap(arr[i + 1], arr[high]);  
    // return its position
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
