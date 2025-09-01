#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Recursive
// Time: O(2^n), Space: O(n)
int rec_helper(int n) {
    if (n == 0) return 1;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += rec_helper(n - i);
    }
    return ans;
}

// Memoization
// Time: O(n^2), Space: O(n)
int memo_helper(int n, vector<int> &dp) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += memo_helper(n - i, dp);
    }
    return dp[n] = ans;
}

// Tabulation (Bottom-Up DP)
// Time: O(n^2), Space: O(n)
int tab_helper(int n, vector<int> &dp) {
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    int n = 7;

    // Recursive
    cout << "Recursive: " << rec_helper(n) << endl;

    // Memoization
    vector<int> dp1(n + 1, -1);
    cout << "Memoization: " << memo_helper(n, dp1) << endl;

    // Tabulation
    vector<int> dp2(n + 1, 0);
    cout << "Tabulation: " << tab_helper(n, dp2) << endl;

    return 0;
}
