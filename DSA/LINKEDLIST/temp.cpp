#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Node{
  public:
  int val;
  Node* next;
  Node(int val){
    this->val=val;
    this->next=NULL;
  }
};

class LinkedList{
  public:
  int size;
  Node* head;
  LinkedList(){
    size=0;
    head=NULL;
  }
  void insertAthead(int val){
    Node* temp = new Node(val);
    if(size==0) head=temp;
    temp->next=head;
    temp=head;
    size++;
  }
  void insertAtTail(int val){
    Node* temp = head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new Node(val);
    size++;
  }
};

int main() {
  // Node* first = new Node(10); // heap allocation need to delete explictelly
  // Node(100); // stack allocation automatically delete when func returns
  return 0;
}