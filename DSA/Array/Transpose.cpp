// leetcode : 867
// link : https://leetcode.com/problems/transpose-matrix
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();  // Rows
        int n = matrix[0].size();  // Columns

        vector<vector<int>> t(n, vector<int>(m));  // Transposed matrix

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j] = matrix[j][i];
            }
        }
        return t;
    }
};

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
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

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    Solution sol;
    vector<vector<int>> transposed = sol.transpose(matrix);

    cout << "Transposed Matrix:" << endl;
    printMatrix(transposed);

    return 0;
}
