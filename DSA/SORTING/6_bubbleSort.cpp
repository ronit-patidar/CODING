#include <iostream>
#include <vector>
using namespace std;
// 🔁 Algorithm Explanation:
// Repeat the process n-1 times (outer loop).

// In each pass, compare adjacent elements and swap if the left one is greater than the right.

// After each pass, the largest unsorted element bubbles up to its correct position.

// If no swap happens in a pass, the array is already sorted → terminate early.


// TIME AND SPACE COMPLEXITY
//  TC = O(N^2) → for all cases (best, average, worst)
//  SC = O(1)   → in-place, no extra memory used


// Optimized Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
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
void runTest(vector<int> arr, string testName) {
    cout << "Test: " << testName << endl;
    cout << "Before: ";
    printArray(arr);
    bubbleSort(arr);
    cout << "After:  ";
    printArray(arr);
    cout << "------------------------" << endl;
}

int main() {
    runTest({1, 2, 3, 4, 5}, "Already Sorted");
    // Pass 1: No swaps → exits early.
    // ✅ Output: 1 2 3 4 5

    runTest({5, 4, 3, 2, 1}, "Reverse Sorted");
    // Maximum number of passes and swaps.
    // ✅ Output: 1 2 3 4 5
    
    runTest({5, 1, 3, 2, 4}, "Random Order");
    // Multiple swaps; sorted in a few passes.
    // ✅ Output: 1 2 3 4 5

    runTest({7, 7, 7, 7, 7}, "All Same Elements");
    // No swaps needed.
    // ✅ Output: 7 7 7 7 7
    runTest({42}, "Single Element");
    // No sorting needed.
    // ✅ Output: 42
    runTest({}, "Empty Array");
    // No sorting needed.
    // ✅ Output: 42
    return 0;
}
