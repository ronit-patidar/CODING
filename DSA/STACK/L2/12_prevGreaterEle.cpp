#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={3,1,2,5,4,6,2,3};
    // -1 3 3 -1 5 -1 6  6
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    stack<int> st;
    for(int i=0;i<n;i++){ 
        while(!st.empty() && arr[i]>=st.top()) st.pop(); // pop

        if(!st.empty() ) ans[i]=st.top(); // ans
        else ans[i]=-1;

        st.push(arr[i]); // push

    }
    for(auto ele:ans){
        cout<<ele<<" ";
    }
}