// leetcode : 106
// link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
    TreeNode* build(vector<int>& in, int il, int ih, vector<int>& po, int pl, int ph) {
        if (il > ih) return NULL; // Base case
        TreeNode* root = new TreeNode(po[ph]); // Root is the last element in the postorder range
        if (il == ih) return root; // Single element, no left or right subtree

        // Find the root in the inorder array
        int i = il;
        while (i <= ih) {
            if (in[i] == po[ph]) break;
            i++;
        }

        int lc = i - il; // Number of nodes in the left subtree

        // Recursively build left and right subtrees
        root->left = build(in, il, i - 1, po, pl, pl + lc - 1);   // Left subtree
        root->right = build(in, i + 1, ih, po, pl + lc, ph - 1); // Right subtree

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n = in.size();
        return build(in, 0, n - 1, po, 0, n - 1);
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
    vector<int> postOrder={4,5,2,6,3,1};
    vector<int> inOrder={4,2,5,1,3,6};
    Solution sol;
    TreeNode* root=sol.buildTree(inOrder,postOrder);
    cout<<"Expected : 1 2 3 4 5 NULL 6 "<<endl;
    levelOrderQueue(root);
}