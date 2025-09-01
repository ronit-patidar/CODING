// https://leetcode.com/problems/set-matrix-zeroes      

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        bool zerothRow = false, zerothCol = false;

        // Check if the 0th row contains any zero
        for (int j = 0; j < n; j++) {
            if (arr[0][j] == 0) {
                zerothRow = true;
                break;
            }
        }

        // Check if the 0th column contains any zero
        for (int i = 0; i < m; i++) {
            if (arr[i][0] == 0) {
                zerothCol = true;
                break;
            }
        }

        // Use the first row and first column to mark zeros
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] == 0) {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }

        // Set elements to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][0] == 0 || arr[0][j] == 0) {
                    arr[i][j] = 0;
                }
            }
        }

        // Handle the zeroth row
        if (zerothRow) {
            for (int j = 0; j < n; j++) {
                arr[0][j] = 0;
            }
        }

        // Handle the zeroth column
        if (zerothCol) {
            for (int i = 0; i < m; i++) {
                arr[i][0] = 0;
            }
        }
    }
};

// Helper function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    Solution sol;
    sol.setZeroes(matrix);

    cout << "Modified Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
