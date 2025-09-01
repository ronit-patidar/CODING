// https://www.geeksforgeeks.org/convert-bst-min-heap/

//  INORDER , PREORDER 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class Solution{
    public:
    void inorder(Node* root,vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void preorder(Node* root,vector<int>& ans,int& i){
        if(root==NULL) return;
        root->val=ans[i++];
        preorder(root->left,ans,i);
        preorder(root->right,ans,i);
    }
    void bstTominheap(Node* root){
       vector<int> ans;
       inorder(root,ans);
       int i=0;
       preorder(root,ans,i);
    }
};
void levelOrderTraversal(Node* root){
    if(root==NULL) return ;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
      }
      cout<<endl;
}
int main(){
    Node* a=new Node(4);
    Node* b=new Node(2);
    Node* c=new Node(6);
    Node* d=new Node(1);
    Node* e=new Node(3);
    Node* f=new Node(5);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    Solution s;
    s.bstTominheap(a);
    levelOrderTraversal(a);
}