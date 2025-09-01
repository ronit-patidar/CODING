// leetcode : 112
// link : https://leetcode.com/problems/path-sum
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
    void helper(TreeNode* root,int targetSum,bool &flag){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
           if(root->val==targetSum){
              flag=true;
           }
        }
        helper(root->left,targetSum-root->val,flag);
        helper(root->right,targetSum-root->val,flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        helper(root,targetSum,flag);
        return flag;
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
    cout<<sol.hasPathSum(root,targetSum);
}