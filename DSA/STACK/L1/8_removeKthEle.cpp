#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> st) {
    stack<int> st2;
    while(st.size() > 0) {
       st2.push(st.top());
       st.pop();
    }
    while(st2.size() > 0) {
       cout << st2.top() << " ";
       st.push(st2.top());
       st2.pop();
    }
    cout << endl;
}
void removeFromBottum(stack<int> &st,int k){ // 0 based indexing
    if(k==0) print(st);
    if(k>st.size()) cout<<"Stack is Full ";
    stack<int> st2;
    int idx=st.size()-k;
    while(--idx){
        st2.push(st.top());
        st.pop();
    }
    st.pop();
    while(st2.size()>0){
        st.push(st2.top());
        st2.pop();
    }
}
void removeFromTop(stack<int> &st,int k){ // 0 based indexing
    if(k==0) print(st);
    if(k>st.size()) cout<<"Stack is Full ";
    stack<int> st2;
    k=2;
    while(--k){
        st2.push(st.top());
        st.pop();
    }
    st.pop();
    while(st2.size()>0){
        st.push(st2.top());
        st2.pop();
    }
}
int main(){
     // remove kth element
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    removeFromBottum(st,2);
    print(st);
    removeFromTop(st,2);
    print(st);
}