#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // either left or right part of target is sorted
        while (lo <= hi) {
            // int mid = (hi + lo) / 2;
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) return mid;

            // if left part is sorted
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && nums[mid] >= target) {
                    // element exist
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // if right part is sorted 
                if (nums[mid] <= target && nums[hi] >= target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {30,31,32,33,1,2,3,4,5};
    int target = 2;
    int index = sol.search(nums, target);
    cout << "Target found at index: " << index << endl;
    return 0;
}
