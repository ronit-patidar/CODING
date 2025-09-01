#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
// Next greater element
// arr 3 1 2 5 4  6  2  3
// ans 5 2 5 6 6 -1  3 -1
// pop,ans,push
// next greater me ulta chalna better hai
// using a stack
// SC O(n) , TC O(n)
// because while lope is not itrating n times it is used to pop and push

int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int nge[n];
    stack<int> st; 
    nge[n-1] = -1;
    st.push(arr[n-1]);
    for(int i = n-2; i >= 0; i--) {
        // Pop elements from the stack while they are less than or equal to arr[i]
        while(st.size() > 0 && st.top() <= arr[i]) st.pop();

        // If the stack is empty, there is no greater element to the right
        if(st.size() == 0) nge[i] = -1;
        else nge[i] = st.top(); // The top element of the stack is the next greater element

        // Push the current element onto the stack
        st.push(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
}
