// leetcode : 102
// link : https://leetcode.com/problems/binary-tree-level-order-traversal
#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
#include<vector>
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
    // level order traversal using queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(q.size()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){ // imp
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(v);
        }
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
    int arr[]={3,9,20,INT_MIN,INT_MIN,15,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);
    for(int i=0;i<ans.size();i++){
         for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
         }
         cout<<endl;
    }
}