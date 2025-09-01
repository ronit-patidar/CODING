#include <iostream>
#include <vector>
using namespace std;

// 🔁 Algorithm Explanation:
// We divide the array into a sorted and an unsorted part.
// Start from index 1 and insert each element into its correct position in the sorted part.
// Shift elements in the sorted part to the right to make space.

// TIME AND SPACE COMPLEXITY
//  TC = O(N^2)    → Worst and average case (reverse sorted)
//  TC = O(N)      → Best case (already sorted)
//  SC = O(1)      → In-place sorting, no extra space used

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift right
            j--;
        }
        // now j is at position where arr[j] is less than key
        arr[j + 1] = key;  // Place key in correct position
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
}

// Test runner
void runTest(vector<int> arr, const string& testName) {
    cout << "Test: " << testName << endl;
    cout << "Before: ";
    printArray(arr);
    insertionSort(arr);
    cout << "After:  ";
    printArray(arr);
    cout << "------------------------" << endl;
}

int main() {
    runTest({1, 2, 3, 4, 5}, "Already Sorted");
    // ✅ Output: 1 2 3 4 5

    runTest({5, 4, 3, 2, 1}, "Reverse Sorted");
    // ✅ Output: 1 2 3 4 5

    runTest({5, 1, 3, 2, 4}, "Random Order");
    // ✅ Output: 1 2 3 4 5

    runTest({1, 2, 5, 4, 3}, "Partially Sorted");
    // ✅ Output: 1 2 3 4 5

    runTest({7, 7, 7, 7, 7}, "All Same Elements");
    // ✅ Output: 7 7 7 7 7

    runTest({42}, "Single Element");
    // ✅ Output: 42

    runTest({}, "Empty Array");
    // ✅ Output:

    return 0;
}
