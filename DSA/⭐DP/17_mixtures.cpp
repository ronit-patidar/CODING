#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long int
using namespace std;

// Function to compute sum of colors from i to j modulo 100
ll g(vector<int> &colors, int i, int j) {
    ll result = 0;
    for (int m = i; m <= j; m++) {
        result = (result + colors[m]) % 100;
    }
    return result;
}

// DP function to find the minimum smoke
ll f(vector<int> &colors, int i, int j, vector<vector<ll>> &dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll result = LLONG_MAX;
    for (int k = i; k <= j - 1; k++) {
        result = min(result,
            f(colors, i, k, dp) +
            f(colors, k + 1, j, dp) +
            g(colors, i, k) * g(colors, k + 1, j));
    }
    return dp[i][j] = result;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }

        vector<vector<ll>> dp(n, vector<ll>(n, -1));  // Initialize all to -1
        cout << f(colors, 0, n - 1, dp) << endl;
    }
    return 0;
}
