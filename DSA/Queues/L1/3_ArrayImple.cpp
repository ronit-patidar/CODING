#include<iostream>
#include<vector>
using namespace std;
// queue from array
class Queue{
public:
   int f;
   int b;
   int s;
   vector<int> arr;
   Queue(int val){
    f=0;
    b=0;
    s=0;
   vector<int> v(val);
    arr=v;
   }

   bool empty(){
        if(s==0) return true;
        else return false;
   }
   int size(){
     return s;
   }

   void push(int val){
    if(b==arr.size()){
        cout<<"Queue is Full!"<<endl;
        return ;
    }
    arr[b]=val;
    b++;
    s++;
   }

   void pop(){ 
    if(s==0){
     cout<<"Queue is empty!"<<endl;
     return;
    }
    f++;
    s--;
   }

   int front(){
        if(s==0){
        cout<<"Queue is empty!"<<endl;
        return -1;
   }
        return arr[f];
   }

   int back(){
        if(s==0){
        cout<<"Queue is empty!"<<endl;
        return -1;
   }
        return arr[b-1];
   }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

}
   