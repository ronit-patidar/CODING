#include <iostream>
#include <vector>
using namespace std;

// 🔁 Algorithm Explanation:
// Repeat the process n-1 times (outer loop).
// In each pass, find the minimum element in the unsorted part of the array.
// Swap the minimum element with the element at the current index.
// This places the smallest element at the correct position after each pass.

// TIME AND SPACE COMPLEXITY
//  TC = O(N^2) → for all cases (best, average, worst)
//  SC = O(1)   → in-place, no extra memory used

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // finding index of minimum element
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr);
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
