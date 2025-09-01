#include <iostream>
#include <vector>
using namespace std;

// Brute Force: O(m*n)
class SolutionBrute {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            for (int val : row) {
                if (val == target)
                    return true;
            }
        }
        return false;
    }
};

// Better: Binary Search on Each Row: O(m * log n)
class SolutionBetter {
public:
    bool binarySearch(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target)
                return true;
            else if (row[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                if (binarySearch(matrix[i], target))
                    return true;
            }
        }
        return false;
    }
};

// Optimal: Treat 2D Matrix as 1D Sorted Array: O(log(m*n))
class SolutionOptimal {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];

            if (midValue == target)
                return true;
            else if (midValue < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 3;

    SolutionOptimal sol;
    if (sol.searchMatrix(matrix, target))
        cout << "Target " << target << " found in the matrix.\n";
    else
        cout << "Target " << target << " NOT found in the matrix.\n";

    return 0;
}
