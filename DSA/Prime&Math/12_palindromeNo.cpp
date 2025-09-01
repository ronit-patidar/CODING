#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
class Solution {
public:
    int reverseNum(int n) {
        int revNum=0;
        while(n != 0){
            int digit=n%10;
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10){
               return 0;
            }
            revNum = (revNum*10) + digit;
            n /= 10;
        }
        return revNum;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==reverseNum(x)) return true;
        return false;
    }
};
int main(){
    Solution sol;
    cout << sol.isPalindrome(121) << endl;        // Expected: 1
    cout << sol.isPalindrome(-121) << endl;       // Expected: 0
    cout << sol.isPalindrome(10) << endl;         // Expected: 0
    cout << sol.isPalindrome(0) << endl;          // Expected: 1
    cout << sol.isPalindrome(1) << endl;          // Expected: 1
    cout << sol.isPalindrome(12321) << endl;      // Expected: 1
    cout << sol.isPalindrome(12345) << endl;      // Expected: 0
    cout << sol.isPalindrome(2147483647) << endl; // Expected: 0
    cout << sol.isPalindrome(INT_MAX) << endl;    // Expected: 0
    cout << sol.isPalindrome(INT_MIN) << endl;    // Expected: 0
    cout << sol.isPalindrome(1001) << endl;       // Expected: 1
    cout << sol.isPalindrome(999999999) << endl;  // Expected: 1
    cout<<sol.isPalindrome(121);

}
