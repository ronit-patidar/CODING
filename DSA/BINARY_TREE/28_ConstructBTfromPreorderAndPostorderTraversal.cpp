// leetcode : 889
// link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
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
    TreeNode* build(vector<int>& pre, int pl, int ph, vector<int>& post, int pol, int poh) {
        if (pl > ph) return nullptr; // Base case: no elements
        TreeNode* root = new TreeNode(pre[pl]); // Create root node
        if (pl == ph) return root; // Base case: single element
        
        // Find the root of the left subtree in postorder
        int leftRootVal = pre[pl + 1];
        int leftSubtreeSize = 0;
        while (post[pol + leftSubtreeSize] != leftRootVal) {
            leftSubtreeSize++;
        }
        leftSubtreeSize++; // Include the left subtree root itself

        // Recursively construct left and right subtrees
        root->left = build(pre, pl + 1, pl + leftSubtreeSize, post, pol, pol + leftSubtreeSize - 1);
        root->right = build(pre, pl + leftSubtreeSize + 1, ph, post, pol + leftSubtreeSize, poh - 1);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return build(pre, 0, n - 1, post, 0, n - 1);
    }
};
void levelOrderQueue(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()>0){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left); // left
        if(temp->right!=NULL) q.push(temp->right); // right
    }
    cout<<endl;
}
int main(){
    vector<int> preorder={1,2,4,5,3,6,7};
    vector<int> postorder={4,5,2,6,7,3,1};
    Solution sol;
    TreeNode* root=sol.constructFromPrePost(preorder,postorder);
    cout<<"Expected : [1,2,3,4,5,6,7] "<<endl;
    levelOrderQueue(root);
    
}