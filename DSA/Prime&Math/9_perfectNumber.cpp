// leetcode : 507
// link : https://leetcode.com/problems/perfect-number


// A perfect number is a positive integer that is equal to the sum of its positive divisors,
//  excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // Perfect numbers are greater than 1
        int sum = 1; // Start with 1 as it's a divisor for all numbers
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) { // Avoid adding square root twice
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << boolalpha; // Print "true" or "false" for boolean values
    cout << "Test Case 1: " << sol.checkPerfectNumber(28) << " (Expected: true)" << endl;
    cout << "Test Case 2: " << sol.checkPerfectNumber(6) << " (Expected: true)" << endl;
    cout << "Test Case 3: " << sol.checkPerfectNumber(496) << " (Expected: true)" << endl;
    cout << "Test Case 4: " << sol.checkPerfectNumber(8128) << " (Expected: true)" << endl;
    cout << "Test Case 5: " << sol.checkPerfectNumber(1) << " (Expected: false)" << endl;
    cout << "Test Case 6: " << sol.checkPerfectNumber(2) << " (Expected: false)" << endl;
    cout << "Test Case 7: " << sol.checkPerfectNumber(12) << " (Expected: false)" << endl;
    cout << "Test Case 8: " << sol.checkPerfectNumber(33550336) << " (Expected: true)" << endl; // Largest perfect number within int range

    return 0;
}
