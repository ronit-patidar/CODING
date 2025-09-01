// leetcode no : 114
// link :  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>             
#include <stack>             
#include <vector>             
using namespace std;
class TreeNode {
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
// method  1
class Solution {
public:
    vector<TreeNode*> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> ans;
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
    return ans;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans = preorderTraversal(root);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
           ans[i]->right=ans[i+1];
           ans[i]->left=NULL;
        }
    }
};
// method 2
class Solution2 {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left); // FLATTEN LEFT SUBTREE
        flatten(root->right); // FLATTEN RIGHT SUBTREE
        TreeNode* rightSubtree = root->right; // STORED RIGHT SUBTREE
        // IF LEFT SUBTREE EXIST
        if (root->left) {
            root->right = root->left; // ROOT->RIGHT KO LEFT BANA DO
            root->left = NULL;  // ROOT->LEFT KO NULL
            TreeNode* temp = root->right; // TREVERSE TEMP TILL FLATTEN ROOT->RIGHT
            while (temp->right) {
                temp = temp->right;
            }
            // NOW LEFTSUBTREE IS ATTACHED TO  ROOT NOW ITS TURN FOR RIGHT SUBTREE 
            temp->right = rightSubtree;
        }
    }
};
// method 3
// best 
// NOT UNLINKING BECAUSE WE HAVE TO CHANGE STRUCTURE OF TREE
class Solution3 {
public:
    void flatten(TreeNode* root) { // Morris traversal O(1)
        if(root==NULL) return;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                // save the right
                TreeNode* r=curr->right;
                curr->right=curr->left;
                // finding pred
                TreeNode* pred=curr->left;
                while(pred->right!=NULL) pred=pred->right;
                //link
                pred->right=r;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp->left=NULL;
            temp=temp->right;
        }
    }
}; 
int main(){

}   