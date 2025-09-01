// Leetcode 62: Unique Paths
// https://leetcode.com/problems/unique-paths
// 4 Possible Solutions with Time & Space Complexity

// 1) Recursion (Brute Force)         -> Time: O(2^(m+n)), Space: O(m+n)
// 2) DP - Memoization (Top Down)     -> Time: O(m*n),     Space: O(m*n + m+n)
// 3) DP - Tabulation (Bottom Up)     -> Time: O(m*n),     Space: O(m*n)

#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion (Brute Force)
int rec_path(int row, int col){
    if(row==0 && col==0) return 1;
    if(row < 0 || col < 0) return 0;
    return rec_path(row-1,col) + rec_path(row,col-1);
}

// 2. Memoization (Top Down)
int memo_path(int row, int col, vector<vector<int>>& dp) {
    if(row==0 && col==0) return 1;
    if(row < 0 || col < 0) return 0;
    if(dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = memo_path(row-1,col,dp) + memo_path(row,col-1,dp);
}

// 3. Tabulation (Bottom Up)
int tab_path(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}


int main() {
    int m = 3, n = 7;

    cout << "Recursive: " << rec_path(m-1,n-1) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization: " << memo_path(m-1, n-1, dp) << endl;

    cout << "Tabulation: " << tab_path(m, n) << endl;


    return 0;
}
