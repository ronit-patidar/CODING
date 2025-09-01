#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n=4;
    int ans = 0;
    vector<int> v={2,1,3,4};
    vector<vector<int>> dp(1005,vector<int>(1000,0));
    for(int len=3;len<=n;len++){
      for(int i=0;i+len-1<n;i++){
        int j=i+len-1;
        dp[i][j]=INT_MAX;
        for(int k=i+1;k<j;k++){
          dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
          ans = dp[i][j];
        }
      }
    }
    cout<<ans<<" ";
    cout<<"DP ARRAY"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}