#include<iostream>
#include<stack>
using namespace std;
void displayrecrev(stack<int> &st){
    // TC O(n), SC O(n) due to callstack there is one stack at changes are occuring with 
    //callstack of recursion and diff values of x
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    cout<<x<<" ";
    displayrecrev(st);
    st.push(x);
}
void displayrec(stack<int> &st){
    // TC O(n), SC O(n) due to callstack there is one stack at changes are occuring with 
    //callstack of recursion and diff values of x
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    displayrec(st);
    st.push(x);
    cout<<x<<" ";
}
void pushatbottom(stack<int> &st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    pushatbottom(st,val);
    st.push(x);
}
void reverse(stack <int> &st){
    if(st.size()==1) return;
      int x=st.top();
      st.pop();
      reverse(st);
      pushatbottom(st,x);
}
int main(){
      stack<int> st;
      //st.top() underflow
      //cout<<st.top() underflow
      //st.pop() underflow
      st.push(10);
      st.push(20);
      st.push(30);
      st.push(40);
      st.push(50);
    //   displayrecrev(st);
    //   cout<<endl;
    //   displayrec(st);
    //   cout<<endl;
    //   pushatbottom(st,-10);
    //   cout<<endl;
      displayrec(st);
      cout<<endl;
      reverse(st);
      displayrec(st);

}