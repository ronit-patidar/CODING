#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
class Node{ // This is tree node at LEETCODE
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
// divide in sub problem while dry run
void displayTree(Node* root){
    if(root==NULL) return ;
   cout<<root->val<<" ";
   displayTree(root->left);
   displayTree(root->right);
}
int sumTree(Node* root){
    if(root==NULL) return 0;
    return root->val + sumTree(root->left) + sumTree(root->right);
}
int productTree(Node* root) {
    if (!root) return 1;
    return root->val * productTree(root->left) * productTree(root->right);
}
int size(Node* root){
    if(root==NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}
int maxInTree(Node* root){
    if(root==NULL) return INT_MIN; 
    // int min work for negative value also
    int lMax=maxInTree(root->left);
    int rMax=maxInTree(root->right);
    return max(root->val,max(lMax,rMax)) ;
}
int minInTree(Node* root){
    if(root==NULL) return INT_MAX; 
    int lMin=minInTree(root->left);
    int rMin=minInTree(root->right);
    return min(root->val,min(lMin,rMin)) ;
}
int levels(Node* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
int height(Node* root){
    if(root==NULL) return 0;
    return levels(root)-1;
}
int main (){
//             1
//           /   \
//         2        3
//      /   \     /   \
//     4     5   6    7
     Node* a=new Node(1);
     Node* b=new Node(2);
     Node* c=new Node(3);
     Node* d=new Node(4);
     Node* e=new Node(5);
     Node* f=new Node(6);
     Node* g=new Node(7);
     a->left=b;
     a->right=c;
     b->left=d;
     b->right=e;
     c->left=f;
     c->right=g;
    cout<<"Tree -> ";
    displayTree(a);
    cout<<endl;  
    cout<<"Sum of Tree -> "<<sumTree(a)<<endl; // 28
    cout<<"Product of Tree -> "<<productTree(a)<<endl;//5040
    cout<<"Max in Tree -> "<<maxInTree(a)<<endl; //7
    cout<<"Min in Tree -> "<<minInTree(a)<<endl;//1
    cout<<"Size of Tree -> "<<size(a)<<endl; // 7
    cout<<"Levels of Tree -> "<<levels(a)<<endl; // 3
    cout<<"Height of Tree -> "<<height(a)<<endl; //2
}