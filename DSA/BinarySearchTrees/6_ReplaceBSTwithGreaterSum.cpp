// leetcode : 1038
// link : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree
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
class Solution {
public:
    void InOrder(TreeNode* root,int &Sum){ 
        if(root==NULL) return ; 
        InOrder(root->right,Sum); 
            root->val=root->val+Sum;
            Sum=root->val; 
        InOrder(root->left,Sum); 
    }
    TreeNode* bstToGst(TreeNode* root) {
        int Sum=0;
        InOrder(root,Sum);
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
    int arr[]={4,1,6,0,2,5,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    TreeNode* ans = sol.bstToGst(root);
    cout<<"[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]"<<endl;
    levelOrderQueue(ans);

}