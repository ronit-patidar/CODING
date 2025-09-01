// Leetcode 746: Min Cost Climbing Stairs
// 4 Possible Solutions with Time & Space Complexity

// 1) Recursion (Brute Force) (tle)    -> Time: O(2^n),     Space: O(n) (call stack)
// 2) DP - Memoization (Top Down) -> Time: O(n),       Space: O(n + n) ~ O(n)
// 3) DP - Tabulation (Bottom Up) -> Time: O(n),       Space: O(n)
// 4) Iterative Optimized         -> Time: O(n),       Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Recursion (Brute Force)
int rec_cost(int i, const vector<int>& cost) {
    if (i >= cost.size()) return 0;
    return cost[i] + min(rec_cost(i + 1, cost), rec_cost(i + 2, cost));
}

// 2. Memoization (Top Down DP)
int memo_cost(int i, const vector<int>& cost, vector<int>& dp) {
    if (i >= cost.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(memo_cost(i + 1, cost, dp), memo_cost(i + 2, cost, dp));
}

// 3. Tabulation (Bottom Up DP)
int dp_cost(const vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);
    dp[n-1]=cost[n-1];
    dp[n-2]=min(cost[n-1],cost[n-2]);
    for(int i=n-3;i>=0;i--){
        dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
    }
    return min(dp[0],dp[1]);
}

// 4. Iterative Optimized
int itr_cost(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];

        for (int i = 2; i < n; i++) {
            int c = cost[i] + min(a, b);
            a = b;
            b = c;
        }

        return min(a, b);
}
int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,};

    cout << "Recursive: " << min(rec_cost(0, cost), rec_cost(1, cost)) << endl;

    vector<int> dp(cost.size(), -1);
    cout << "Memoization: " << min(memo_cost(0, cost, dp), memo_cost(1, cost, dp)) << endl;

    cout << "Tabulation: " << dp_cost(cost) << endl;

    cout << "Iterative: " << itr_cost(cost) << endl;

    return 0;
}
