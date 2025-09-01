// leetcode : 100
// link : https://leetcode.com/problems/same-tree
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
    // Function to determine if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, both trees are empty, so they are identical
        if (p == NULL && q == NULL) return true;
        
        // If one node is NULL and the other is not, trees are not identical
        if (p == NULL || q == NULL) return false;

        // If the values of the current nodes are different, trees are not identical
        if (p->val != q->val) return false;

        // Recursively check if the left subtrees are identical
        bool leftans = isSameTree(p->left, q->left);
        if (leftans == false) return false; // If left subtrees aren't identical, return false

        // Recursively check if the right subtrees are identical
        bool rightans = isSameTree(p->right, q->right);
        if (rightans == false) return false; // If right subtrees aren't identical, return false

        // If both left and right subtrees are identical, return true
        return true;
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
    int arr[]={1,2,3};
    int brr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    TreeNode* p = construct(arr,n);
    TreeNode* q = construct(brr,m);
    Solution sol;
    cout<<sol.isSameTree(p,q)<<endl; 
}