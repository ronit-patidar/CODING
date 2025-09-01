// leetcode no : 1
// link : https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else m[nums[i]]=i; // store the current number nums[i] and its index i 
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=sol.twoSum(nums,target);
    for(int ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
