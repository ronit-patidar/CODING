// leetcode : 240
// link : https://leetcode.com/problems/search-a-2d-matrix-ii
// this code is little bit changed by me
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace  std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target,int &a,int &b) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0;
        int col=cols-1;
        while(row<rows && col>=0){
            if(matrix[row][col] == target){
                a=row;
                b=col;
                return true;
            }
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    int a=0;
    int b=0;
    Solution sol;
    bool flag = sol.searchMatrix(matrix,target,a,b);
    if(flag==1) cout<<"Present at "<<"("<<a<<","<<b<<")";
    else cout<<"Not Present"<<endl;
}