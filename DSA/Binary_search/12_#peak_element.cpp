#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int findPeakElement(vector<int> &arr) {
        int n = arr.size(); //Size of array.

        // Edge cases:
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            //If arr[mid] is the peak:
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            // If we are in the left:
            if (arr[mid] > arr[mid - 1]) low = mid + 1;

            // If we are in the right:
            // Or, arr[mid] is a common point:
            else high = mid - 1;
        }
        // Dummy return statement
        return -1;
    }
};int main() {
    Solution sol;

    vector<int> test1 = {1};                     // Only one element → peak at 0
    vector<int> test2 = {5, 3, 2};               // Peak at index 0
    vector<int> test3 = {1, 3, 5, 4, 2};         // Peak at index 2
    vector<int> test4 = {1, 2, 3, 4, 5};         // Peak at last index
    vector<int> test5 = {10, 20, 15, 2, 23, 90, 67}; // Peaks at index 1 or 5
    vector<int> test6 = {3, 4, 3, 2, 1};         // Peak at index 1
    vector<int> test7 = {1, 2};                  // Peak at index 1
    vector<int> test8 = {2, 1};                  // Peak at index 0

    cout << sol.findPeakElement(test1) << endl;
    cout << sol.findPeakElement(test2) << endl;
    cout << sol.findPeakElement(test3) << endl;
    cout << sol.findPeakElement(test4) << endl;
    cout <<sol.findPeakElement(test5) << endl;
    cout << sol.findPeakElement(test6) << endl;
    cout << sol.findPeakElement(test7) << endl;
    cout << sol.findPeakElement(test8) << endl;

    return 0;
}
