//  leetcode -> 509
// https://leetcode.com/problems/fibonacci-number 

// 4 POSSIBLE SOLTUION

// 1) RECURSION O(2^n) O(n) DUE TO CALL STACK OF RECURSION (TLE)

// 2) DP (TOP DOWN APPROACH) MEMOIZATION O(n) O(n+n) ~ O(n) DUE TO CALLSTACK + DP ARRAY

// 3) DP (BOTTUM UP APPROACH) TABULATION O(n)  O(n)  DP ARRAY

// 4) ITRATIVE O(N) O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int brute_fib(int n) { // recursion
    if(n <= 1 ) return n;
    return brute_fib(n-1) + brute_fib(n-2);
}
int fibo(int n,vector<int> &dp){ // memoization
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n];
}
int dp_fib(int n) {
    if(n<=1) return n;
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int iterative_fib(int n) {
    if(n<=1) return n;
    int a,b;
    a=0;
    b=1;
    for(int i=2;i<=n;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
}
int main() {
    int n = 4;

    cout << "Recursive: " << brute_fib(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << fibo(n, dp) << endl;

    cout << "Tabulation: " << dp_fib(n) << endl;

    cout << "Iterative: " << iterative_fib(n) << endl;

    return 0;
}