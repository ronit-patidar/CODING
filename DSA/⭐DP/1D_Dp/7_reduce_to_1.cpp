#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// min steps to reduce n to 1
// valid operation 
// n -> n-1
// n is even -> n/2
// if n is divisible by 3 -> n / 3

// O(n) O(n)
int helper(int n,vector<int> &dp){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n] != -1) return dp[n];
    int x = n%2==0 ? helper(n/2,dp) : INT_MAX;
    int y = n%3==0 ? helper(n/3,dp) : INT_MAX;
    return dp[n] = 1 + min(helper(n-1,dp),min(x,y));
}

// O(n) O(n)
int tabulation(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<dp.size();i++){
        if(i%2==0 && i%3==0) dp[i] = 1 + min(dp[i-1],min(dp[i/2],dp[i/3]));
        else if(i%2==0) dp[i] = 1 + min(dp[i/2],dp[i-1]);
        else if(i%3==0) dp[i] = 1 + min(dp[i/3],dp[i-1]);
        else dp[i] = 1 + dp[i-1];
    }
    return dp[n];
}
int main() {
    int n=12;
    vector<int> dp(n+1,-1);
    cout<<helper(n,dp);
    cout<<endl;
    cout<<tabulation(n);
}