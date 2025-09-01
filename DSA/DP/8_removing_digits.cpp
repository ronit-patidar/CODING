#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
// n -> 0 find minSteps
// n me se khud ki digits substract kar sakte he 
// O(log10 n) O(logn)
void getDigits(int n,vector<int>& result){
    while(n>0){
        int lastDigit=n%10;
        if(lastDigit != 0) result.push_back(lastDigit);
        n=n/10;
    }
}
// O(n * logn) O(n)
int helper(int n,vector<int> &dp){
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    if(n<=9) return 1;
    vector<int> digits;
    getDigits(n,digits);
    int minSteps=INT_MAX;
    for(int i=0;i<digits.size();i++){
        minSteps=min(minSteps,helper(n-digits[i],dp));
    }
    return dp[n] = 1+minSteps;
}
// O(n * logn) O(n)
int tab_fbu(int num,vector<int>& dp){
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int n=10;n<=num;n++){
        vector<int> d;
        getDigits(n,d);
        int result = INT_MAX;
        for(int i=0;i<d.size();i++){
            result = min(result,dp[n-d[i]]);
        }
        dp[n]=1+result;
    }
    return dp[num];
}
int main() {
    int n=27;
    vector<int> dp(n+1,-1);
    cout<<helper(n,dp);
    cout<<endl;
    vector<int> dp2(n+1,-1);
    cout<<tab_fbu(n,dp2);
}