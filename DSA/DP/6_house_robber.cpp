// Leetcode 198: House Robber
// 4 Possible Solutions:

// 1) Recursion (Brute Force)       O(2^n)   | O(n)
// 2) DP - Memoization (Top Down)   O(n)     | O(n + call stack)
// 3) DP - Tabulation (Bottom Up)   O(n)     | O(n)
// 4) Iterative (Space Optimized)   O(n)     | O(1)

#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion (Brute Force)
int rec_rob(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;
    return max(rec_rob(i + 1, nums), nums[i] + rec_rob(i + 2, nums));
}

// 2. Memoization (Top Down)
int memo_rob(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(memo_rob(i + 1, nums, dp), nums[i] + memo_rob(i + 2, nums, dp));
}

// 3. Tabulation (Bottom Up)
int dp_rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
}

// 4. Iterative (Space Optimized)
int itr_rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int p2 = nums[0];
    int p1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        int curr = max(p1, nums[i] + p2);
        p2 = p1;
        p1 = curr;
    }
    return p1;
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Recursion:     " << rec_rob(0, nums) << endl;

    vector<int> dp(nums.size(), -1);
    cout << "Memoization:   " << memo_rob(0, nums, dp) << endl;

    cout << "Tabulation:    " << dp_rob(nums) << endl;
    cout << "Iterative:     " << itr_rob(nums) << endl;

    return 0;
}
