// leetcode no : 2442
// link : https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int reverse(int n) {
        int r = 0;
        while (n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]);
            s.insert(rev);
            s.insert(nums[i]);
        }
        return s.size();
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 13, 10, 31, 30};
    cout << sol.countDistinctIntegers(nums1) << endl; // Expected output: 6

    // Test case 2
    vector<int> nums2 = {123, 321, 456};
    cout << sol.countDistinctIntegers(nums2) << endl; // Expected output: 4

    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    cout << sol.countDistinctIntegers(nums3) << endl; // Expected output: 1

    return 0;
}
