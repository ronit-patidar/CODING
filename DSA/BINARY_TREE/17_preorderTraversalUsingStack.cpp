// leetcode : 144
// link : https://leetcode.com/problems/binary-tree-preorder-traversal
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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
    vector<int> preorderTraversal(TreeNode* root) {
        // root left right
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        vector<int> ans;
        while(st.size()>0){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right) st.push(temp->right);// right
            if(temp->left) st.push(temp->left);//left
            // because of last in first out 
            // left is last so it come first
        } 
        return ans;
    }
};
int size(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
int main(){
  // Tree structure:
    //             1
    //           /   \
    //         2        3
    //      /   \     /   \
    //     4     5   6     7    

    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);
     a->left=b;
     a->right=c;
     b->left=d;
     b->right=e;
     c->left=f;
     c->right=g;
    Solution sol;
    vector<int> ans=sol.preorderTraversal(a);
    cout << "Preorder traversal: ";
    cout <<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}