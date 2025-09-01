// leeetcode : 861
// link : https://leetcode.com/problems/score-after-flipping-matrix
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Flip rows if the first column is 0
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Flip columns to maximize 1s
        for (int i = 1; i < n; i++) {
            int noz = 0, noo = 0;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] == 0) noz++;
                else noo++;
            }
            if (noz > noo) {
                for (int j = 0; j < m; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }

        // Calculate final score
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int x = 1;
            for (int j = n - 1; j >= 0; j--) {
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};

// Function to print the grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid elements (0s and 1s):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Original Grid:" << endl;
    printGrid(grid);

    Solution sol;
    int result = sol.matrixScore(grid);

    cout << "Maximized Score: " << result << endl;

    return 0;
}
