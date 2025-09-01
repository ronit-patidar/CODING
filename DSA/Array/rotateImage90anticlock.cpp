#include <iostream>
#include <vector>
#include <algorithm>  // For reverse function
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step 2: Reverse each column
        for(int c=0;c<n;c++){
            int i=0;
            int j=n-1;
            while(i<j){
                swap(matrix[i][c],matrix[j][c]);
                i++;
                j--;
            }
        }
    }
};

int main() {
    // Create an instance of Solution
    Solution sol;
    
    // Test Case 1: 3x3 Matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Rotate the matrix 90 degrees anti clockwise
    sol.rotate(matrix);
    
    // Print the rotated matrix
    cout << "Rotated Matrix:" << endl;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
