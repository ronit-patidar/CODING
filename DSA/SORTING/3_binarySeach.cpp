#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 🔁 Algorithm Explanation:
// 1. Start with the entire sorted array (low = 0, high = n-1).
// 2. Find the middle index (mid).
// 3. If arr[mid] == target → return mid (target found).
// 4. If arr[mid] < target → search in the right half.
// 5. If arr[mid] > target → search in the left half.
// 6. Repeat until low > high → target not found.

// TIME AND SPACE COMPLEXITY
//  TC = O(log N)  → divides the search range in half each step
//  SC = O(1)      → iterative approach (no recursion)

// Binary Search - Returns index of target or -1 if not found
int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
}

// Test runner
void runTest(vector<int> arr, int target, const string& testName) {
    cout << "Test: " << testName << endl;
    cout << "Array:  ";
    printArray(arr);
    cout << "Target: " << target << endl;

    sort(arr.begin(), arr.end());  // Binary search needs sorted array
    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "✅ Found at index: " << result << endl;
    else
        cout << "❌ Not found" << endl;

    cout << "------------------------" << endl;
}

int main() {
    runTest({1, 2, 3, 4, 5}, 3, "Target in Middle");
    // ✅ Output: index 2

    runTest({10, 20, 30, 40, 50}, 10, "Target at Start");
    // ✅ Output: index 0

    runTest({10, 20, 30, 40, 50}, 50, "Target at End");
    // ✅ Output: index 4

    runTest({4, 2, 5, 1, 3}, 6, "Target Not Present");
    // ❌ Output: Not found

    runTest({7, 7, 7, 7, 7}, 7, "All Elements Same");
    // ✅ Output: index of any 7 (like 2)

    runTest({1}, 1, "Single Element Present");
    // ✅ Output: index 0

    runTest({1}, 2, "Single Element Absent");
    // ❌ Output: Not found

    runTest({}, 5, "Empty Array");
    // ❌ Output: Not found

    return 0;
}
