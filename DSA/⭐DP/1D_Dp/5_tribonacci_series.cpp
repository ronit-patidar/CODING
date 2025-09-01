// Leetcode 1137: N-th Tribonacci Number
// 4 Possible Solutions

// 1) Recursion (Brute)             O(3^n)   O(n)
// 2) DP - Memoization (Top Down)  O(n)     O(n + call stack)
// 3) DP - Tabulation (Bottom Up)  O(n)     O(n)
// 4) Iterative (Space Optimized)  O(n)     O(1)

#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion (Brute Force)
int rec_trib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return rec_trib(n-1) + rec_trib(n-2) + rec_trib(n-3);
}

// 2. Memoization (Top Down)
int memo_trib(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = memo_trib(n-1, dp) + memo_trib(n-2, dp) + memo_trib(n-3, dp);
}

// 3. Tabulation (Bottom Up)
int dp_trib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

// 4. Iterative (Space Optimized)
int itr_trib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; i++) {
        int d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    int n = 5;
    cout << "Recursion: " << rec_trib(n) << endl;

    vector<int> dp(n+1, -1);
    cout << "Memoization: " << memo_trib(n, dp) << endl;

    cout << "Tabulation: " << dp_trib(n) << endl;
    cout << "Iterative: " << itr_trib(n) << endl;

    return 0;
}
