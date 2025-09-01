// leetcode : 102
// link : https://leetcode.com/problems/binary-tree-level-order-traversal
// O(n2)
// O(n+h)
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class TreeNode{ // This is treenode at LEETCODE
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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nthLevel(TreeNode* root,int curr,int level,vector<int>& v){ 
        if(root==NULL) return ; 
        if(curr==level){
            v.push_back(root->val);
            return ;    
        }
        nthLevel(root->left,curr+1,level,v);  
        nthLevel(root->right,curr+1,level,v); 
    }
    void lOrder(TreeNode* root,vector<vector<int>>& ans){// tc and sc
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthLevel(root,1,i,v);
            ans.push_back(v);
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
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
    vector<vector<int>> ans=sol.levelOrder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}