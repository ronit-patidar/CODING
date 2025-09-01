#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to return the nth term of the "Count and Say" sequence
    string countAndSay(int n) {
        // Base case: the first term is "1"
        if(n == 1) return "1";

        // Recursively get the (n-1)th term
        string str = countAndSay(n - 1);
        string result = ""; // To store the result for the current term

        int freq = 1;       // Frequency counter
        char ch = str[0];   // Start by looking at the first character

        // Loop through the string starting from the second character
        for(int i = 1; i < str.size(); i++) {
            char current = str[i];
            if(ch == current) {
                // Same character: increase frequency
                freq++;
            } else {
                // Different character: append count and previous character
                result += to_string(freq) + ch;
                ch = current; // Update current character
                freq = 1;     // Reset frequency
            }
        }

        // Add the last counted group to result
        result += to_string(freq) + ch;

        return result;
    }
};

int main() {
    Solution sol;

    int n = 5; // Example input: Get the 5th term of the sequence

    string output = sol.countAndSay(n);

    cout << "The " << n << "th term of the Count and Say sequence is: " << output << endl;

    return 0;
}
