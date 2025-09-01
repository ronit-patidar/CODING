#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    FUNCTION: partition (Lomuto Partition Scheme)

    ALGORITHM:
    1. Choose the last element as pivot.
    2. Initialize a pointer 'idx' to track the position for smaller elements.
    3. Traverse from lo to hi - 1:
       - If current element is smaller than pivot:
         - Increment idx.
         - Swap current element with element at idx.
    4. After loop, place pivot in its correct position (idx + 1).
    5. Return the index of the pivot (idx + 1).
*/
// TC = O(nlogn) best,avg  O(n^2) in worst case if arr is reverse sorted 
// SC = O(n)
// Function to partition the array using Lomuto partition scheme
int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[hi]; // Choosing the last element as the pivot
    int idx = lo - 1;    // Index of smaller element

    // Traverse the array and rearrange elements such that
    // all elements less than pivot are on the left
    for (int i = lo; i < hi; i++) {
        if (arr[i] < pivot) {
            idx++;
            swap(arr[idx], arr[i]); // Place smaller element at correct position
        }
    }

    // Place the pivot after the last smaller element
    idx++;
    swap(arr[idx], arr[hi]);
    return idx; // Return the index of pivot
}
// Recursive QuickSort function
void quickSort(vector<int>& arr, int lo, int hi) {
    if (lo < hi) {
        // Partition the array and get the pivot index
        int partitionIdx = partition(arr, lo, hi); 
        // this will find the correct index of element

        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, lo, partitionIdx - 1);   // Left side of pivot
        quickSort(arr, partitionIdx + 1, hi);   // Right side of pivot
    }
}
int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    quickSort(arr, 0, arr.size() - 1);
    for (auto ele : arr) {
        cout << ele << " ";
    }
    return 0;
}
