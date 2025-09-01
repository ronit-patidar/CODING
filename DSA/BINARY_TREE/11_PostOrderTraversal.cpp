// leetcode : 145
// link : https://leetcode.com/problems/binary-tree-postorder-traversal
// DFS
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class TreeNode{ // This is tree node at LEETCODE
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
    void helper(TreeNode* root,vector<int>& ans){
        if(root==NULL) return ; // base call
        helper(root->left,ans); // left
        helper(root->right,ans); // right
        ans.push_back(root->val); // root
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
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
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr,n);
    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);
    for(int ele : ans){
        cout<<ele<<" ";
    }
}