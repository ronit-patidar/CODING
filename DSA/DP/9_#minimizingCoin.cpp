#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://cses.fi/problemset/task/1634


int helper(int x, vector<int> &coins, vector<int> &dp) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];

    int result = INT_MAX;
    for (int j = 0; j < coins.size(); j++) {
        int coin = coins[j];
        if (coin > x) continue;

        int subResult = helper(x - coin, coins, dp);
        if (subResult != -1) {
            result = min(result, subResult + 1);
        }

        // result = min(result,helper(x-coin,coins,dp));
    }

    dp[x] = (result == INT_MAX ? -1 : result);
    return dp[x];
}

int main() {

    // testcase 1
    vector<int> coins={1,5,7};
    int x=11;

    // testcase 2
    // vector<int> coins={3,6};
    // int x=10;
    
    // testcase 3   
    // vector<int> coins={2,4};
    // int x=10;

    // int n,x;
    // cin>>n>>x;
    // vector<int> coins;
    // coins.clear();
    // for(int i=0;i<n;i++){
    //     int num;
    //     cin>>num;
    //     coins.push_back(num);
    // }

    vector<int> dp(x+1,-1);
    cout<<helper(x,coins,dp);
    return 0;
}
