#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_c
// O(n * 3) O(n * 3)
int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> dp(n,vector<int>(3,0));

    int a,b,c;      // a->0,b->1,c->2
    cin>>a>>b>>c;
    dp[0][0]=a;
    dp[0][1]=b;
    dp[0][2]=c;
    
    for(int i=1;i<n;i++){
        // input of happiness at ith day
        cin>>a>>b>>c;
        // ith day -> a
        dp[i][0] = a + max(dp[i-1][1],dp[i-1][2]);
        // ith day -> b 
        dp[i][1] = b + max(dp[i-1][0],dp[i-1][2]);
        // ith day -> c
        dp[i][2] = c + max(dp[i-1][0],dp[i-1][1]);
        
    }
// 7 
// 6 7 8
// 8 8 3
// 2 5 2
// 7 8 6
// 4 6 8
// 2 3 4
// 7 5 1

    cout<<"Maximum Happiness : "<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    return 0;
}
