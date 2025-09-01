#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// try tabulation 
const int N = 3005;
vector<vector<int>> dp(N, vector<int>(N, -1));
vector<int> arr(N);

int f(int i, int j) {
    if (i == j) return arr[i];
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << f(0, n - 1) << endl;
    return 0;

  // 6
  // 4 2 9 7 1 5

}
