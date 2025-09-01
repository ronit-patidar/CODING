// leetcode 75 
// https://leetcode.com/problems/sort-colors

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
        int maxArea=0;
        while(i<j){
            int length=j-i;
            int width=min(height[i],height[j]);
             area=length*width;
             maxArea=max(maxArea,area);
            if(height[i]<=height[j]) i++; //imp 
            // because we have to maintain max piller/wall
            else j--;
        }
        return maxArea;
    }
};
int main(){
    vector<int> matrix={1,8,6,2,5,4,8,3,7};
    Solution sol;
    int maxarea=sol.maxArea(matrix);
    cout<<maxarea;
}