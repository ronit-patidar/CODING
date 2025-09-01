#include<iostream>
#include<stack>
using namespace std;
// stack and linkedlist size are unlimited
int main(){
    stack<int> st;
    stack<int> st2;
    // cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // cout<<st.size()<<endl;
    // st.pop();
    // cout<<st.size()<<endl;
    // cout<<st.top()<<endl;

    // printing in top->bottom order and push back elements to st2 because st is empty while printing
    // also our stack in reverse order with the help of another stack
    while(st.size()!=0){ 
       cout<<st.top()<<" ";
       st2.push(st.top()); // filling in reverse order
       st.pop();
    }
    cout<<endl;
    // wapas st me elements push kiye and print in bottum to top
    while(st2.size()!=0){
       cout<<st2.top()<<" ";
       st.push(st2.top());
       st2.pop();
    }
    cout<<endl;
    cout<<st.size()<<endl;//5
    cout<<st.top()<<endl;
    cout<<st2.size()<<endl;//0
}