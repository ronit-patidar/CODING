// leetcode : 98
// link : https://leetcode.com/problems/validate-binary-search-tree
#include<iostream>
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
// M1 INORDER TRAVERSAL OF BST IS SORTED 
// FIND INORDER TRAVERSL IF INORDER IS SORTED THEN IT IS BST

//  M 2 
class Solution {
public:
    void inorder(TreeNode* root,TreeNode* prev,bool & flag){
        if(root==NULL) return ;
        inorder(root->left,prev,flag);
        if(prev!=NULL && prev->val > root->val ){ // imp
            flag=false;
            return ;
        }
        prev=root;
        inorder(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool flag = true;
        inorder(root,prev,flag);
        return flag;
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
void levelOrderQueue(TreeNode* root){ // BFS
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()>0){
        TreeNode* temp = q.front(); // STORE 
        q.pop(); // POP 
        cout<<temp->val<<" "; 
        if(temp->left!=NULL) q.push(temp->left);    // left
        if(temp->right!=NULL) q.push(temp->right);  // right
    }
    cout<<endl;
}

int main(){
    int arr[]={2,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    bool ans = sol.isValidBST(root);
    cout<<ans;
    

}