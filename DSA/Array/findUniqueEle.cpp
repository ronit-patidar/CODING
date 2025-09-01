// leetcode : 136
// link : https://leetcode.com/problems/single-number
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        // 0^x = x; 
        // y^y = 0;
        // XOR is commutative ( order does not matter )
        // ex 1 = 0^2^2^1 = 1
        // ex 2 = 0^4^2^2^1^1 = 4
        for(int i=0;i<n;i++){
            res ^= nums[i];
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> num={2,2,1};
    vector<int> num2={4,1,2,1,2};
    int ans=sol.singleNumber(num);
    int res=sol.singleNumber(num2);
    cout<<"Expected ans 1 : "<<ans<<endl;
    cout<<"Expected ans 4 : "<<res<<endl;
}