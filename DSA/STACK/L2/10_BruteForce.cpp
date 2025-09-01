#include <iostream>
#include <string>
using namespace std;
string removeConsecutiveDuplicates(string s) {
    string result; 
    result += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            result += s[i];
        }
    }
    return result; 
}
int main() {
    string s = "aaabbcddaabffg"; 
    cout << "Original string: " << s << endl;
    string modifiedString = removeConsecutiveDuplicates(s);
    cout << "Modified string: " << modifiedString << endl;
    return 0;
}
