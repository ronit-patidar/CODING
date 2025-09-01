// leetcode no : 1814
// link : https://leetcode.com/problems/count-nice-pairs-in-an-array

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reverse(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + (n % 10);  // Extract the last digit and add to r
            n /= 10;                // Remove the last digit from n
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> m;
        int mod = 1000000007;

        // Calculate nums[i] - reverse(nums[i]) for each element
        for (int i = 0; i < n; i++) {
            nums[i] -= reverse(nums[i]);
        }

        // Count nice pairs
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                count = (count + m[nums[i]]) % mod;  // Correct way to update count with modulus
            }
            m[nums[i]]++;
        }

        return count;  // Return the final count
    }
};

int main() {
    Solution sol;

    // Test input
    vector<int> nums = {13,10,35,24,76};

    // Call the countNicePairs function
    int result = sol.countNicePairs(nums);

    // Print the result
    cout << "Number of nice pairs: " << result << endl;

    return 0;
}
