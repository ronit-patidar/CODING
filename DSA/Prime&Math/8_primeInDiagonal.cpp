// leetcode : 2614
// link : https://leetcode.com/problems/prime-in-diagonal

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPrime(int n) { 
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) { // Optimized to avoid sqrt calculation
            if (n % i == 0) return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) { // Main and anti-diagonals
                    if (checkPrime(nums[i][j])) {
                        maxi = max(maxi, nums[i][j]);
                    }
                }
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<vector<int>> test1 = {{2, 3, 5}, {7, 11, 13}, {17, 19, 23}};
    cout << "Max prime on diagonals (test1): " << sol.diagonalPrime(test1) << endl;

    vector<vector<int>> test2 = {{1, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    cout << "Max prime on diagonals (test2): " << sol.diagonalPrime(test2) << endl;

    vector<vector<int>> test3 = {{1}};
    cout << "Max prime on diagonals (test3): " << sol.diagonalPrime(test3) << endl;

    vector<vector<int>> test4 = {{29, 2, 17}, {3, 11, 5}, {7, 23, 31}};
    cout << "Max prime on diagonals (test4): " << sol.diagonalPrime(test4) << endl;

    vector<vector<int>> test5 = {{31, 37, 41}, {43, 47, 53}, {59, 61, 67}};
    cout << "Max prime on diagonals (test5): " << sol.diagonalPrime(test5) << endl;

    return 0;
}
