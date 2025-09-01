// leetcode 50
// https://leetcode.com/problems/powx-n

// aRaisedToPowerBusingRecursion
#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
// TC = O(log n)
// SC = O(log n)
class Solution {  // optimized 
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1.0;  // Base case: x^0 = 1
    
            // If n is negative, take the reciprocal of x
            if (n < 0) {
                x = 1 / x;
                
                // Special case: if n == INT_MIN (-2147483648)
                // We cannot do `n = -n` because -(-2147483648) overflows
                // Instead, we break it down using:
                // x^(-2147483648) = x^(-(2147483647+1))
                //                 = x^(-2147483647) * x^(-1)
                //                 = (1 / (x^2147483647)) * (1 / x)
                //                 = 1 / (x^2147483647 * x)
                return (n == INT_MIN) ? x * myPow(x, INT_MAX) : myPow(x, -n);
            }
    
            // Recursive binary exponentiation: divide exponent by 2
            double half = myPow(x, n / 2);
    
            // If n is even: x^n = (x^(n/2)) * (x^(n/2))
            // If n is odd:  x^n = (x^(n/2)) * (x^(n/2)) * x
            return (n % 2 == 0) ? half * half : half * half * x;
        }
    };
    int main(){
    cout<<"Inbuilt function   : "<<pow(2,5)<<endl;  // inbuild
    cout<<"Optimized Solution : "<<pow(2,5)<<endl; // not for negative case 
}