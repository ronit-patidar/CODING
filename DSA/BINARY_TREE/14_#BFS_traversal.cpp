#include<iostream>
#include<queue>
using namespace std;
class Node{ // This is treenode at LEETCODE
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
int height(Node* root){
    if(root==NULL) return 0;
    return levels(root)-1;
}
int levels(Node* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
void printnthLevel(Node* root,int curr,int level){ 
//  TC -> O(n) 
//  SC  ->  O(h) 
// left to right
   if(root==NULL) return ; // base case
   if(curr==level){
        cout<<root->val<<" "; // root
        return ;
   }
   printnthLevel(root->left,curr+1,level);  // left
   printnthLevel(root->right,curr+1,level); // right
}
void levelorder(Node* root,int curr){
//  O(nlogn) -> O(n)     tc
//  (h)      -> O(logn)  sc
    int n = levels(root);
    for(int i=1;i<=n;i++){
        printnthLevel(root,1,i);
        cout<<endl;
    }
}
void printnthLevelRev(Node* root,int curr,int level){ 
//  TC -> O(n) 
//  SC  ->  O(h) 
// right to level
   if(root==NULL) return ; // base case
   if(curr==level){
        cout<<root->val<<" "; // root
        return ;
   }
   printnthLevelRev(root->right,curr+1,level); // right
   printnthLevelRev(root->left,curr+1,level);  // left
}
void levelOrderQueue(Node* root){ // BFS
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front(); // STORE 
        q.pop(); // POP 
        cout<<temp->val<<" "; 
        if(temp->left!=NULL) q.push(temp->left);    // left
        if(temp->right!=NULL) q.push(temp->right);  // right
    }
    cout<<endl;
}
void levelOrderQueueRev(Node* root){ // BFS , IMP
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front(); // to access left and right
        q.pop(); 
        cout<<temp->val<<" ";
        if(temp->right!=NULL) q.push(temp->right); // right
        if(temp->left!=NULL) q.push(temp->left);  // left
    }
    cout<<endl;
}
int main (){
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
    // printnthLevel(a,1,3); // nth level
    // cout<<endl;
    // printnthLevelRev(a,1,3); // nth level
    // cout<<endl;
    //levelorder(a,1);// level order
    levelOrderQueue(a); // printing throught queue
    cout<<endl;
    levelOrderQueueRev(a); // printing throught queue in reverse order
    cout<<endl;
    
}