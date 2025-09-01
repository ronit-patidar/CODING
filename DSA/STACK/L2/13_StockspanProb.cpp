#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={100,80,60,81,70,60,75,85};
    // 1 1 1 3 1 1 3 7
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans[n];
    stack<int> st;
    for(int i=0;i<n;i++){ 
        while(!st.empty() && arr[i]>=arr[st.top()]) st.pop(); // pop

        if(!st.empty() ) ans[i]=st.top(); // ans
        else ans[i]=-1;

        ans[i]=i-ans[i]; //imp

        st.push(i); // push

    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}