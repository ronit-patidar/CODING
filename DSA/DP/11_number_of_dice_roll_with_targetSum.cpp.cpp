#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long int
#define mod 1000000007

// 2d dp array 

// | i\d | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
// | --- | - | - | - | - | - | - | - | - |
// | 0   | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
// | 1   | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
// | 2   | 0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
class Solution {
public:
    int helper(int n,int k,int t,vector<vector<int>> &dp){
        if(n==0 && t==0) return 1;
        if(n==0) return 0;
        if(dp[n][t] != -1) return dp[n][t];
        int sum=0;
        for(int v=1;v<=k;v++){
            if(v > t) break; // all value are larger
            sum = ((sum%mod) +  (helper(n-1,k,t-v,dp)%mod)%mod) ;
        }
        return dp[n][t] = sum%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        // t -> target
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(n,k,target,dp);
    }
};
int main() {
    int n=2;
    int k=6;
    int t=7;
    Solution sol;
    // cout<<sol.numRollsToTarget(n,k,t);

    return 0;
}