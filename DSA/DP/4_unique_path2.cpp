// Leetcode 63: Unique Paths II (with obstacles)
// 3 Possible Solutions with Time & Space Complexity

// 1) Recursion (Brute Force)         -> Time: O(2^(m+n)), Space: O(m+n)
// 2) DP - Memoization (Top Down)     -> Time: O(m*n),     Space: O(m*n + m+n)
// 3) DP - Tabulation (Bottom Up)     -> Time: O(m*n),     Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion (Brute Force)
int rec_path(int row, int col, const vector<vector<int>>& obstacleGrid) {
    if(row < 0 || col < 0 || obstacleGrid[row][col] == 1) return 0;
    if(row == 0 && col == 0) return 1;
    return rec_path(row-1, col, obstacleGrid) + rec_path(row, col-1, obstacleGrid);
}

// 2. Memoization (Top Down)
int memo_path(int row, int col, const vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    if(row < 0 || col < 0 || obstacleGrid[row][col] == 1) return 0;
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = memo_path(row-1, col, obstacleGrid, dp) + memo_path(row, col-1, obstacleGrid, dp);
}
// ⭐
// 3. Tabulation (Bottom Up)
int tab_path(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    if (grid[0][0] == 1) return 0;
    grid[0][0] = 1;

    // First column
    for (int i = 1; i < m; ++i)
        grid[i][0] = (grid[i][0] == 0 && grid[i - 1][0] == 1) ? 1 : 0;

    // First row
    for (int j = 1; j < n; ++j)
        grid[0][j] = (grid[0][j] == 0 && grid[0][j - 1] == 1) ? 1 : 0;

    // Fill rest of the grid
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == 0)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            else
                grid[i][j] = 0;
        }
    }

    return grid[m - 1][n - 1];
}
int main() {
    vector<vector<int>> obstacleGrid = {
        {0,1},
        {0,0},
    };
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    cout << "Recursive: " << rec_path(m-1, n-1, obstacleGrid) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization: " << memo_path(m-1, n-1, obstacleGrid, dp) << endl;

    cout << "Tabulation: " << tab_path(obstacleGrid) << endl;

    return 0;
}
