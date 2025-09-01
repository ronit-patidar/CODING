#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// lt - 64
// try tabulation method 
class Solution {
public:
    vector<vector<int>> dp;

    int helper(vector<vector<int>>& grid, int row, int col) {
        if (row == 0 && col == 0) return grid[0][0];
        if (row < 0 || col < 0) return INT_MAX;

        if (dp[row][col] != -1) return dp[row][col];

        int up = helper(grid, row - 1, col);
        int left = helper(grid, row, col - 1);

        return dp[row][col] = grid[row][col] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return helper(grid, m - 1, n - 1);
    }
};
