#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void display(queue<int>& q){
   int n=q.size();
   for(int i=1;i<=n;i++){
         int x=q.front();
         cout<<x<<" ";
         q.pop();
         q.push(x);
   }
   cout<<endl;
}
void reverseK(int k,queue<int> &q){
    stack<int> st;
    int n=q.size();
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
}
int main(){
    // inp  1 2 3 4 5 6
    // o/p   2 1 3 4 5 6
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);
    int k=6;
    reverseK(k,q);
    display(q);
}