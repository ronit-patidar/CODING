#include <iostream>
#include <vector>
using namespace std;

// Function to generate binary strings
void generateBinaryStrings(string ans, int n) {
    if (ans.length() == n) {  // Base case: when string length reaches 'n'
        cout << ans << endl;
        return;
    }
    
    // Append '0' and recurse
    generateBinaryStrings(ans + "0", n);
    
    // Append '1' and recurse
    // if(ans.empty() || ans.back() != '1') (this condition remove string that contain consecutive ones)
    generateBinaryStrings(ans + "1", n);
}

int main() {
    int n = 3;  // Change 'n' to generate strings of different lengths
    generateBinaryStrings("", n);
}

// Q1 print binary string .

// Q2
// output will  be after removing strings that conatin consecutive ones 
// 000
// 001
// 010
// 100
// 101
