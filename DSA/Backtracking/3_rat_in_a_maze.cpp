#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int n, int i, int j, vector<vector<int>> &grid) {
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0;
}

void explorePaths(vector<vector<int>> &grid, int n, int i, int j, int &count) {
    if (i == n - 1 && j == n - 1) {
        count++;
        return;
    }

    grid[i][j] = 2; // Mark as visited

    // left
    if (isSafe(n, i, j - 1, grid)) explorePaths(grid, n, i, j - 1, count);
    // up
    if (isSafe(n, i - 1, j, grid)) explorePaths(grid, n, i - 1, j, count);
    // right
    if (isSafe(n, i, j + 1, grid)) explorePaths(grid, n, i, j + 1, count);
    // down
    if (isSafe(n, i + 1, j, grid)) explorePaths(grid, n, i + 1, j, count);

    grid[i][j] = 0; // Backtrack
}

int ratInAMaze(vector<vector<int>> &grid, int n) {
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0; // No path if start or end blocked

    int count = 0;
    explorePaths(grid, n, 0, 0, count);
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    // start point = grid[0][0]
    // destination = grid[6][6]
    // 0 -> open rat can go.
    // 1 -> blocked rat cannot go.
    // 2 we take as visited. 
    cout << ratInAMaze(grid, 4);
    // 4 paths
}
