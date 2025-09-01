#include<iostream>
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
int levels(Node* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
void printnthLevel(Node* root,int curr,int level){ 
   if(root==NULL) return ; 
   if(curr==level){
        cout<<root->val<<" "; 
        return ;
   }
   printnthLevel(root->left,curr+1,level);  
   printnthLevel(root->right,curr+1,level); 
}
void levelorder(Node* root,int curr){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        printnthLevel(root,1,i);
        cout<<endl;
    }
}
int minimumInTree(Node* root){
    if(root==NULL) return -1 ;
    if(root->left==NULL) return root->val;
    return minimumInTree(root->left);
}
int maximumInTree(Node* root){
    if(root==NULL) return -1 ;
    if(root->right==NULL) return root->val;
    return maximumInTree(root->right);
}
// PREDECCESSER / SUCCESSOR KE KABHI BHI 2 CHILD NHI HOTE
// ? YA TOH LEFT CHILD HOTA HAI YA LEAF NODE  HOTA HAI

// PREDECCESSER OF INORDER TRAVERSAL
int predecessor(Node* root){
    if(root->left==NULL) return -1; // if root->left is NULL then there is no predecessor   
    Node* pred=root->left;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred->val;
}
// SUCCESSOR OF INORDER TRAVERSAL
int successor(Node* root){
    if(root->right==NULL) return -1; // if root->right is NULL then there is no successor   
    Node* succ=root->right;
    while(succ->left!=NULL){
        succ=succ->left;
    }
    return succ->val;
}