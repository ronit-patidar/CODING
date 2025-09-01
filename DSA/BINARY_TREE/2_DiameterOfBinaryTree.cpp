// leetcode : 543
// link : https://leetcode.com/problems/diameter-of-binary-tree

// imp observation
// The diameter of a binary tree is the length of the longest path 
// between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges
// between them.
#include<iostream>
#include<queue>
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
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root,int &maxDia){
        if(root==NULL) return ;
        int dia = levels(root->left) + levels(root->right);
        maxDia=max(dia,maxDia);
        helper(root->left,maxDia); // for LST
        helper(root->right,maxDia); // for RST
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;
        helper(root,maxDia);
        return maxDia;
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
    // I cant use NULL in arr because NULL is pointer and arr is of int type.
    // so instead of NULL i use INT_MIN in this code.
    // on coding platform use NULL.
    int arr[]={4,-7,-3,INT_MIN,INT_MIN,-9,-3,9,-7,-4,INT_MIN,6,INT_MIN,-6,-6,INT_MIN,INT_MIN,0,6,5,INT_MIN,9,INT_MIN,INT_MIN,-1,-4,INT_MIN,INT_MIN,INT_MIN,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    cout<<"Diameter of Binary Tree is "<<sol.diameterOfBinaryTree(root)<<"."<<endl; 
}