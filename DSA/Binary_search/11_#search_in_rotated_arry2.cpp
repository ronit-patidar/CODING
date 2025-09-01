//  this may contain duplicates elements 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // either left or right part of target is sorted
        while (lo <= hi) {
            // int mid = (hi + lo) / 2;
            int mid = lo + (hi - lo) / 2;

            if (target == nums[mid]) return true;

            // if left part is sorted
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
                continue;
            }

            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && nums[mid] >= target) {
                    // element exist
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else { // if right part is sorted 
                if (nums[mid] <= target && nums[hi] >= target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2,2,3,2,2,2};
    int target = 1;

    bool found = sol.search(nums, target);
    if (found) {
        cout << "Target found in array." << endl;
    } else {
        cout << "Target not found in array." << endl;
    }

    return 0;
}
