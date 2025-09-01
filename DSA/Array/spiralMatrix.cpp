// https://leetcode.com/problems/spiral-matrix
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minr = 0, maxr = matrix.size() - 1;
        int minc = 0, maxc = matrix[0].size() - 1;
        vector<int> ans;

        while (minr <= maxr && minc <= maxc) {
            // Right
            if (minr > maxr || minc > maxc) break;
            for (int j = minc; j <= maxc; j++) {
                ans.push_back(matrix[minr][j]);
            }
            minr++;

            // Down
            if (minr > maxr || minc > maxc) break;
            for (int i = minr; i <= maxr; i++) {
                ans.push_back(matrix[i][maxc]);
            }
            maxc--;

            // Left
            if (minr > maxr || minc > maxc) break;
            for (int j = maxc; j >= minc; j--) {
                ans.push_back(matrix[maxr][j]);
            }
            maxr--;

            // Up
            if (minr > maxr || minc > maxc) break;
            for (int i = maxr; i >= minr; i--) {
                ans.push_back(matrix[i][minc]);
            }
            minc++;
        }
        return ans;
    }
};

// Function to print the result
void printVector(const vector<int>& result) {
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
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

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    printVector(result);

    return 0;
}
