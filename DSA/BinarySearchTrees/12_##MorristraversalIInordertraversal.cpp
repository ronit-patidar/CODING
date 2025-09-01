// leetcode : 94
// link : https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){ // find the pred
               TreeNode* pred=curr->left;
               while(pred->right!=NULL && pred->right!=curr){
                 pred=pred->right;
               }
               if(pred->right==NULL){ // link
                 pred->right=curr;
                 curr=curr->left;
               }
               else{ // pred->right==curr : unlink
                 pred->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
               }
            }
            else { // curr ->left == NULL 
              // if left doesnt exist then print the root and move to right
              ans.push_back(curr->val);
              curr=curr->right;
            }
        }
        return ans;
    }
};
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    levelOrder(root->left);
    levelOrder(root->right);
}
int main() {
}
