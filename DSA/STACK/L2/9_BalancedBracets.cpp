#include<iostream>
#include<stack>
using namespace std;
bool isbalancedbracket(string s) {
    if(s.length() % 2 != 0) return false;
    stack<char> st; 
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') st.push(s[i]); 
        else { // If the current character is ')'
            if(st.size() == 0) return false; // If the stack is empty, return false (unmatched closing bracket)
            else st.pop(); // Otherwise, pop the top element from the stack (matching opening bracket)
        }
    }
    return st.size() == 0 ; 
}
int main() {
    string s = "()()()"; 
    cout << isbalancedbracket(s); 
}
