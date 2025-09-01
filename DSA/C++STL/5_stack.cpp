#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void print(stack<int> &st){
    stack<int> st2;
   while(!st.empty()){
       cout<<st.top()<<" ";
       st2.push(st.top());
       st.pop();
   }
   st.swap(st2);
}
int main(){
    stack<int> st;
    stack<int> s2;
    st.push(1);
    st.emplace(2);
    st.push(3);
    print(st);
    cout<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    s2.swap(st);
    // now all values of st is in s2 and st is empty
    cout<<st.size()<<endl;
    cout<<s2.size()<<endl;
} 