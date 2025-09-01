// leetcode : 110
// link : https://leetcode.com/problems/balanced-binary-tree
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
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
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    int height(TreeNode* root){
        return levels(root) - 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int hl = height(root->left);
        int hr = height(root->right);

        // Check if the current node is balanced
        int bf = abs(hl-hr);  // balance factor
        if(bf > 1) return false;

        // Recursively check if the left and right subtrees are balanced
        // if bf of single node is differ by more than 1 then it cant be balanced
        return isBalanced(root->left) && isBalanced(root->right);
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
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    Solution sol;
    cout<<sol.isBalanced(root);
}