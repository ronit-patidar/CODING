// leetcode : 236
// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
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
    bool exists(TreeNode* root, TreeNode* target) {
        if (root == NULL) return false;
        if (root == target) return true;
        // Recursively check left and right subtrees
        // either it is in left or in right
        return exists(root->left, target) || exists(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        bool pInLeft = exists(root->left, p);
        bool qInRight = exists(root->right, q);
        bool pInRight = exists(root->right, p);
        bool qInLeft = exists(root->left, q);
        if (pInLeft && qInRight || (pInRight && qInLeft)) return root;
        if (pInLeft && qInLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (pInRight && pInRight) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If none of the above cases, return the current root
        return root;
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
    int arr[]={3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root,p,q);
    cout<<ans->val;
}