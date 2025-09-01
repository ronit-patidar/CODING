#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
//TC O(n) SC O(n)
// Function to remove consecutive duplicates from a string
string removeduplicates(string s) {
    stack<char> st; 
    st.push(s[0]);
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != st.top()) st.push(s[i]);
    }
    s = ""; 
    while(st.size() > 0) {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s; // Return the modified string
}
int main() {
    string s = "aaabbcddaabffg";
    cout << s << endl; 
    s = removeduplicates(s); 
    cout << s << endl; 
}
