#include <iostream>
#include <vector>
using namespace std;
// also try tabulation method 
class Solution {
public:
    // Recursive function with memoization to calculate number of unique BSTs
    int f(int n, vector<int> &dp) {
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) return dp[n];

        int sum = 0;
        for (int k = 1; k <= n; k++) {
            sum += f(k - 1, dp) * f(n - k, dp);
        }
        return dp[n] = sum;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of unique BSTs: " << sol.numTrees(n) << endl;
    return 0;
}
