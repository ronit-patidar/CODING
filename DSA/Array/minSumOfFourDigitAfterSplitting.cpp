// leetcode : 2160
// link : https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int minimumSum(int n) {
        vector<int> ans; // to stor digits of num

        int ones = n%10 ; // 2
        ans.push_back(ones);
        n /= 10; //293

        int tenses = n%10 ; // 3
        ans.push_back(tenses);
        n /= 10; // 29

        int hunds = n%10 ; // 9
        ans.push_back(hunds);
        n /= 10; //2

        int thous = n%10 ; //2
        ans.push_back(thous);
        n /= 10; //0

        sort(ans.begin(),ans.end());    

        int num1 = ans[0];
        num1 *= 10;
        num1 += ans[2];

        int num2 = ans[1];
        num2 *= 10;
        num2 += ans[3];
    return (num1+num2);
    }
};
int main(){
    Solution sol;

    int num=2932;
    int ans = sol.minimumSum(num);
    cout<<"Expected sum is 52 : "<<ans<<endl;

    int temp=9004;
    int res = sol.minimumSum(temp);
    cout<<"Expected sum is 13 : "<<res<<endl;
}