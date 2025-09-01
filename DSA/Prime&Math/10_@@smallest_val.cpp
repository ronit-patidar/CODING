// leetcode : 2507
//  https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
class Solution {
public:
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
    int smallestValue(int n) { // O(sqrt(n)nlogn)
        if(isPrime(n)) return n;
        int sum=0;
        // kaam
        for(int i=1;i<sqrt(n);i++){// O(sqrt(n))
            if(n%i==0 && isPrime(i)){
                int m=n;
                while(m%i==0){// O(logn)
                    sum+=i;
                    m/=i;
                }
            }
        }
        for(int i=sqrt(n);i>=1;i--){
            if(n%i==0 && isPrime(n/i)){
                int m=n;
                    while(m%(n/i)==0){
                        sum+=(n/i);
                        m/=(n/i);
                    }
                }
            }
        if(sum==n) return n;
        return smallestValue(sum);
    }
};
int main(){
    Solution sol;
 // Test Cases
    cout << sol.smallestValue(12) << endl;   // Expected: 5
    cout << sol.smallestValue(15) << endl;   // Expected: 5
    cout << sol.smallestValue(28) << endl;   // Expected: 6
    cout << sol.smallestValue(1) << endl;    // Expected: 1
    cout << sol.smallestValue(6) << endl;    // Expected: 5
    cout << sol.smallestValue(10) << endl;   // Expected: 5
    cout << sol.smallestValue(50) << endl;   // Expected: 7
    cout << sol.smallestValue(31) << endl;   // Expected: 31 (prime)
    cout << sol.smallestValue(100) << endl;  // Expected: 10
    cout << sol.smallestValue(120) << endl;  // Expected: 6
    cout << sol.smallestValue(1024) << endl; // Expected: 2
    cout << sol.smallestValue(999) << endl;  // Expected: 9
}