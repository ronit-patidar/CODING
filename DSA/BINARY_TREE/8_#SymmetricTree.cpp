// leetcode : 101
// link : https://leetcode.com/problems/symmetric-tree
#include<iostream>
#include<vector>
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
    // Helper function to check if two subtrees are symmetric.
    bool checkSymmetric(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;  // Both subtrees are empty, hence symmetric.
        if (p == NULL || q == NULL) return false; // One subtree is empty and the other is not, not symmetric.
        
        // Recursively check if the current nodes are equal and their corresponding subtrees are mirrors.
        return (p->val == q->val) && 
               checkSymmetric(p->left, q->right) && 
               checkSymmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root){
        if (root == NULL) return true;  // An empty tree is symmetric.
        // Check if the left and right subtrees of the root are mirrors of each other.
        return checkSymmetric(root->left, root->right);
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
    int arr[]={1,2,2,3,4,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    Solution sol;
    cout<<sol.isSymmetric(root);
}