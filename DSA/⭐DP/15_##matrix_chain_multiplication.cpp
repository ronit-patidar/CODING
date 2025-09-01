#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if( i + 1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = INT_MAX;
    for(int k = i + 1; k < j; k++) {
        int cost = f(i, k, arr, dp) + f(k, j, arr, dp) + arr[i] * arr[k] * arr[j];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main() {
    int n = 4;
    vector<int> v = {2,1,3,4};
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << f(0, n - 1, v, dp) << endl;  // Output: 26000
    cout<<"DP ARRAY"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
  
    return 0;
}
//    DP ARRAY
// -1 -1 6 20 
// -1 -1 -1 12 
// -1 -1 -1 -1 
// -1 -1 -1 -1 
