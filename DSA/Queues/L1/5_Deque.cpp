#include<iostream>
using namespace std ;
// design deque from doubly linked list
 #include<iostream>
using namespace std;
class Node{ // user defined datatype
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Deque{ // user defined data structure
public:
     Node* head; // NULL ka val , next nahi hota 
     Node* tail;
     int s;
    Deque(){
           head=tail=NULL;
           s=0;
    } 
   void push_back(int val){
       Node* temp=new Node(val);
       if(s==0){
        head=tail=temp;
       }
       else{
        tail->next=temp;
        temp->prev=tail;//extra
        tail=temp;
       }
       s++;
   }
   void push_front(int val){
       Node* temp=new Node(val);
       if(s==0){
        head=tail=temp;
       }
       else{
        temp->next=head;
        head->prev=temp;//extra
        head=temp;
       }
       s++;
   }
    void pop_front(){
        if(s==0) {
            cout<<"LL is empty ";
            return;
        }
        head=head->next;
        if(head)head->prev=NULL;// extra 
        if(head==NULL) tail=NULL;//extra
        s--;
    }
    void pop_back(){
        if(s==0){
        cout<<"LL is empty ";
        return;
        } 
        else if(s==1){// extra
            pop_front();
        return;
        } 
        Node* temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        s--;
    }
    void display(){
      Node* temp=head;
      while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
      }
      cout<<endl;
    }
    int front(){
        if(s==0) {
            cout<<"Queue is empty "<<endl;
            return -1;
        }
    return head->val;
   }
   int back(){
        if(s==0) {
            cout<<"Queue is empty "<<endl;
            return -1;
        }
    return tail->val;
   }
    bool empty(){
        if(s==0) return true;
        else return false;
   }
   int size(){
     return s;
   }


};
int main(){
    Deque dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.display();
    dq.pop_back();
    dq.display();
    dq.pop_front();
    dq.display();
    dq.pop_front();
    dq.display();
    dq.push_front(50);
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}
