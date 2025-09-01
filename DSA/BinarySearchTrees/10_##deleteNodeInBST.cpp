// leetcode : 450. Delete Node in a BST
// lnik : https://leetcode.com/problems/delete-node-in-a-bst/
#include<iostream>
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
class Solution {
public:  
    TreeNode* iop(TreeNode* root){ // inorder predeccessor
        // no need to write base case
        // because we know node has 2 child 
        // root->left!=NULL
        TreeNode* pred=root->left;
        while(pred->right!=NULL){
             pred=pred->right;
        }
        return pred;
    }

    TreeNode* ios(TreeNode* root){ // inorder successor
        // no need to write base case
        // because we know node has 2 child 
        // root->right!=NULL
        TreeNode* succ=root->right;
        while(succ->left!=NULL){
             succ=succ->left;
        }
        return succ;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
             // case 1 : (leaf node)
            if(root->left==NULL && root->right==NULL) return NULL;
            //  case 2 : (one child)
            else if (root->left==NULL || root->right==NULL)
            {
                if(root->left!=NULL) return root->left;
                else return root->right;
            } 
            // case 3 : 2 child nodes
            //  root->left!=NULL || root->right!=NULL
            // replace the root with its inorder pred/succ
            else {
               TreeNode* pred=iop(root);
               root->val=pred->val;
               root->left = deleteNode(root->left,pred->val);
                // after replacing delete the pred/succ
            }
        }
        else if(root->val > key){  
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};
void levelorder(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    levelorder(root->left);
    levelorder(root->right);
}
int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(7);
    Solution sol;
    TreeNode* ans=sol.deleteNode(root,3);
    cout<<"Expected : [5,4,6,2,null,null,7]"<<endl;
    levelorder(ans);
    return 0;
    
}   