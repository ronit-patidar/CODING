#include <iostream>
#include <vector>
using namespace std;

// Algorithm:(Divide and conquer algorithm)
// 1. MergeSort recursively divides the array into two halves until each half contains a single element.
// 2. After the division, it merges the sorted halves into a single sorted array using the merge function.

//  TC = O(nlogn)
//  SC = O(N)

// Merging two sorted halves of the array
void merge(vector<int> &arr, int st, int mid, int end) {
    int i = st, j = mid + 1;
    vector<int> v;

    // Merging elements from two halves into the temporary vector
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) v.push_back(arr[i++]);
        else v.push_back(arr[j++]);
    }

    // Adding remaining elements from the first half, if any
    while (i <= mid) v.push_back(arr[i++]);

    // Adding remaining elements from the second half, if any
    while (j <= end) v.push_back(arr[j++]);

    // Copying the sorted elements back to the original array
    for (int idx = 0; idx < v.size(); idx++) {
        arr[st + idx] = v[idx];
    }
}

// MergeSort function to sort the array
void mergeSort(vector<int> &arr, int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);        // Sorting the first half
        mergeSort(arr, mid + 1, hi);    // Sorting the second half
        merge(arr, lo, mid, hi);        // Merging the sorted halves
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 5, 7, 6, 8};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto ele : arr) cout << ele << " ";
    return 0;
}



// Test Cases:

// Test Case 1:
// Input: [4, 2, 1, 3, 5, 7, 6, 8]
// Output: 1 2 3 4 5 6 7 8

// Test Case 2:
// Input: [9, 7, 5, 3, 1]
// Output: 1 3 5 7 9

// Test Case 3:
// Input: [1, 2, 3, 4, 5]
// Output: 1 2 3 4 5

// Test Case 4:
// Input: [5, 2, 8, 6, 1, 3, 4, 7]
// Output: 1 2 3 4 5 6 7 8

// Test Case 5:
// Input: [1]
// Output: 1

// Test Case 6:
// Input: [2, 1]
// Output: 1 2
// 
