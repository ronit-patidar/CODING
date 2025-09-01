#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    // This function finds the row index of the maximum element in the 'mid' column
    int func(int mid, vector<vector<int>>& mat) {
        int max_ele = INT_MIN;
        int idx = -1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][mid] > max_ele) {
                max_ele = mat[i][mid]; // Update max value
                idx = i;               // Store row index of the max value
            }
        }
        return idx; // Return the row index of the max element in column 'mid'
    }

    // Main function to find any peak element in the 2D matrix
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lo = 0;
        int hi = mat[0].size() - 1; // Binary search on columns

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // Middle column index
            int row = func(mid, mat);     // Get the row index of max element in 'mid' column

            // Get left and right neighbors (boundary check included)
            int left = (mid - 1 >= 0 ? mat[row][mid - 1] : -1);
            int right = (mid + 1 < mat[0].size() ? mat[row][mid + 1] : -1);

            // If current element is greater than both neighbors, it's a peak
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid}; // Return position of peak element
            }
            // If left neighbor is greater, move search space to left
            else if (mat[row][mid] < left) {
                hi = mid - 1;
            }
            // Otherwise, move to the right half
            else {
                lo = mid + 1;
            }
        }

        return {-1, -1}; // Should not reach here if a peak always exists
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2}}; // Sample 2D matrix
    vector<int> result = sol.findPeakGrid(mat); // Call function to find peak
    cout << "Peak at: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
