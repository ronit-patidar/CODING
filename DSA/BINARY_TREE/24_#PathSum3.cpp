// leetcode : 437
// link : https://leetcode.com/problems/path-sum-iii
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
    void helper(TreeNode* root, long long sum, int& count) {
        if (root == NULL) return;
        if ((long long)(root->val) == sum) {
            count++;
        }
        helper(root->left, sum - (long long)(root->val), count);
        helper(root->right, sum - (long long)(root->val), count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        int count = 0;
        helper(root, (long long)(targetSum), count);
        count += (pathSum(root->left, targetSum) + pathSum(root->right, targetSum));
        return count;
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
int main(){
    int arr[]={10,5,-3,3,2,INT_MIN,11,3,-2,INT_MIN,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode* root=construct(arr,n);
    Solution sol;
    int targetSum=8;
    cout<<"Count is  "<<sol.pathSum(root,targetSum);
}