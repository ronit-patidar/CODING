#include<iostream>
using namespace std;

int main() {
    string s = "abbcdeffghh";  // you can replace this with `cin >> s;` to input a string
    int count = 0;
    int n = s.size();
    
    if (n == 1) {  // If string has only 1 character, no need to count
        cout << 0;
        return 0;
    }
    
    // Check first character
    if (s[0] != s[1]) {
        count++;
    }
    
    // Check middle characters
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            count++;
        }
    }
    
    // Check last character
    if (s[n - 1] != s[n - 2]) {
        count++;
    }
    
    cout << count;
    return 0;
}
