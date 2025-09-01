// leetcode : 199
// leetcode : https://leetcode.com/problems/binary-tree-right-side-view
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
// method 1
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return  0;
        return 1 + max(levels(root->left),levels(root->right));
    } 
    void preorder(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL) return ;
        ans[level]=root->val;
        // left right
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }
};
// method 2
class Solution2 {
public:
    int levels(TreeNode* root){
        if(root==NULL) return  0;
        return 1 + max(levels(root->left),levels(root->right));
    } 
    void nthLevel(TreeNode* root,int curr,int level,vector<int> &ans){
        if(root==NULL) return ;
        if(curr==level){
            ans[curr]=root->val;
            return ; 
        }
        nthLevel(root->left,curr+1,level,ans);
        nthLevel(root->right,curr+1,level,ans);
    }
    void levelOrder(TreeNode* root,vector<int> &ans){
        int n = levels(root);
        for(int i=0;i<n;i++){
           nthLevel(root,0,i,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        levelOrder(root,ans);
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
      // Tree structure:
    //             1
    //           /   \
    //         2        3
    //      /   \     /   \
    //     4     5   6     7    
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    TreeNode* root=construct(arr,n);
    Solution2 sol;
    vector<int> ans=sol.rightSideView(root);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
}