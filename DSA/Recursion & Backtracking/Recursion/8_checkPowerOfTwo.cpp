// given a positive integer , return true if it is power of two.
// leetcode : 231
// link : https://leetcode.com/problems/power-of-two
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true; // 2^0 = 1
        if(n==0 || n%2!=0) return false;
        return isPowerOfTwo(n/2);
    }
};
int main(){
   Solution Sol;
   int n=33;
   bool ans = Sol.isPowerOfTwo(n);
   cout<<ans<<endl;
}