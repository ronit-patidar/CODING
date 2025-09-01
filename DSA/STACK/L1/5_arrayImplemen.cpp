#include<iostream>
using namespace std;
class stack {
public:
    int arr[5]; 
    int idx;    
    stack() {
        idx = -1; // Constructor: Initialize idx to -1 to indicate an empty stack
    }
    void push(int val) {
        if(idx == sizeof(arr)/sizeof(arr[0]) - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        idx++;          
        arr[idx] = val; 
    }
    void pop() {
        if(idx == -1) { 
            cout << "Stack is empty" << endl;
            return;
        }
        idx--;
    }
    int top() {
        if(idx == -1) { 
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return arr[idx]; 
    }

    int size() {
        return idx + 1; 
    }

    void display(stack &st) {
        for(int i = 0; i < idx + 1; i++) { 
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
};
int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6); 
    cout << st.top() << endl; 
    st.display(st);
    return 0;
}
