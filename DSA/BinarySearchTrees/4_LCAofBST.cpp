// leetcode : 235
// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // if(root->val==p->val || root->val==q->val) return root;
        // else if(root->val > p->val && root->val < q->val) return root;
        // else if(root->val < p->val && root->val > q->val) return root;
        // else if(root->val < p->val && root->val  < q->val) return lowestCommonAncestor(root->right,p,q);
        // else { //(root->val > p->val && root->val  > q->val) 
        //     return lowestCommonAncestor(root->left,p,q);
        // }
        
        if((root->val < p->val && root->val  < q->val) ) return lowestCommonAncestor(root->right,p,q);
        else if((root->val > p->val && root->val  > q->val) ) return lowestCommonAncestor(root->left,p,q);
        else return root;
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
    int arr[]={6,2,8,0,4,7,9,INT_MIN,INT_MIN,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    Solution sol;
    TreeNode* p = new TreeNode(2); 
    TreeNode* q = new TreeNode(8);
    TreeNode* ans = sol.lowestCommonAncestor(root, p,q);
    cout<<ans->val;
    

}