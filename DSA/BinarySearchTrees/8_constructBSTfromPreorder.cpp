// leetcode no : 1008
// link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val < val){ // go right
            if(root->right==NULL){
                root->right=new TreeNode(val);
            }
            else  insertIntoBST(root->right,val);
        }
        else{// root->val > val : go left
            if(root->left==NULL) {
                root->left=new TreeNode(val);
            }
            else  insertIntoBST(root->left,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
             insertIntoBST(root,pre[i]);
        }
        return root;
    }
};// Level-order traversal function to display the tree
void levelOrderQueue(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {8,5,1,7,10,12}; // Input sorted array
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(arr); // Convert to BST
    cout << "Level-order traversal of the constructed BST:" << endl;
    levelOrderQueue(root); // Print level-order traversal
    return 0;
}
