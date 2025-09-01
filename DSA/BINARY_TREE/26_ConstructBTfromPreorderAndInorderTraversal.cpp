// leetcode : 105
// link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* build(vector<int> &pre,int prelo,int prehi,vector<int> &in,int inlo,int inhi){
        if(prelo > prehi) return NULL;
        // OR if(inlo>inhi) return NULL;
        TreeNode* root=new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;
        // OR if(inlo==inhi) return root;
        int i=inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break;
            i++;
        }
        int leftCount=i-inlo;
        int rightCount=inhi-i;
        root->left = build(pre,prelo+1,prelo+leftCount,in,inlo,i-1);
        root->right = build(pre,prelo+leftCount+1,prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return build(pre,0,n-1,in,0,n-1);
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
    vector<int> preOrder={1,2,4,5,3,6};
    vector<int> inOrder={4,2,5,1,3,6};
    Solution sol;
    TreeNode* root=sol.buildTree(preOrder,inOrder);
    cout<<"Ans : [1,2,3,4,5,NULL,6]"<<endl;
    // CODE IS CORRECT BUT IT CANT PRINT NULL
    levelOrderQueue(root);
    
}