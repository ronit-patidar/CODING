#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    stack<int> st2;
    stack<int> st3;
    st.push(100);
    st.push(90);
    st.push(80);
    st.push(70);
    st.push(60);
    st.push(50);
    while(st.size()!=0){
       cout<<st.top()<<" ";
       st2.push(st.top());
       st.pop();
    }
    cout<<endl;
    while(st2.size()!=0){
        cout<<st2.top()<<" ";
        st3.push(st2.top());
        st2.pop();
    }
    cout<<endl;
    while(st3.size()!=0){
        cout<<st3.top()<<" ";
        st.push(st3.top());
        st3.pop();
    }
    cout<<endl;
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    cout<<st.size()<<endl;
    cout<<st2.size()<<endl;
    cout<<st3.size()<<endl;
}