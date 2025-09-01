// leetcode : 113
// link : https://leetcode.com/problems/path-sum-ii
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;
class TreeNode{ 
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
       this->val=val;
       this->left=NULL;
       this->right=NULL;
    }
};
class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int> v, vector<vector<int>> &ans) {
        if (root == NULL) return;

        v.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) ans.push_back(v);
            return;
        }

        helper(root->left, targetSum - root->val, v, ans);
        helper(root->right, targetSum - root->val, v, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, v, ans);
        return ans;
    }
};

TreeNode* construct(int arr[],int n){
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        if(arr[i]!=INT_MIN) l=new TreeNode(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new TreeNode(arr[j]);
        else r=NULL;

        temp->left=l;
        temp->right=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
int main(){
    int arr[]={5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr,n);
    Solution sol;
    int targetSum=22;
    vector<vector<int>> ans=sol.pathSum(root,targetSum);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}