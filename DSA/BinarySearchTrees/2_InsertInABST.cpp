// leetcode : 701
// link : https://leetcode.com/problems/insert-into-a-binary-search-tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val < val){ // go right
            if(root->right==NULL){
                TreeNode* temp=new TreeNode(val);
                root->right=temp;
            }
            else  insertIntoBST(root->right,val);
        }
        else{// root->val > val : go left
            if(root->left==NULL) {
                TreeNode* temp=new TreeNode(val);
                root->left=temp;
            }
            else  insertIntoBST(root->left,val);
        }
        return root;
    }
};TreeNode* construct(int arr[],int n){
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
    //     4
    //    / \
    //   2   7
    //  / \
    // 1   3
    int arr[]={4,2,7,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    int val = 5;
    TreeNode* result = sol.insertIntoBST(root, val);
    levelOrderQueue(result);
    

}