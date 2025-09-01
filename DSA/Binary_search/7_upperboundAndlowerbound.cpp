// 🔍 Definitions:
// ✅ Lower Bound:(index)
// The first position (smallest index) where the value is greater than or equal to the target.

// ✅ Upper Bound:(index)
// The first position where the value is strictly greater than the target.


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // note: right is nums.size()
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // first position where nums[i] >= target
    // return right; left and right are at same idx retunr any 
}
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size(); // same pattern
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    // return right; left and right are at same idx retunr any 
    return left; // first position where nums[i] > target
}
int main() {
    vector<int> nums = {1,2,4,4,4,6,7};
    int target = 4;

    // vector<int> nums = {2, 3, 7, 10, 11, 11, 25};
    // int target = 100;
     
    int lb = lowerBound(nums, target);
    int ub = upperBound(nums, target);

    cout << "Lower Bound Index: " << lb << endl;
    cout << "Upper Bound Index: " << ub << endl;

    return 0;
}