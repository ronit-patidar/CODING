// leetcode : 263
// limk :  https://leetcode.com/problems/ugly-number
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Ugly numbers are positive

        // Divide n by 2, 3, and 5 as much as possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        // If n becomes 1, it is an ugly number
        return n == 1;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.isUgly(1) << " (Expected: 1)" << endl;     // 1 is an ugly number
    cout << sol.isUgly(6) << " (Expected: 1)" << endl;     // 6 = 2 × 3
    cout << sol.isUgly(8) << " (Expected: 1)" << endl;     // 8 = 2 × 2 × 2
    cout << sol.isUgly(14) << " (Expected: 0)" << endl;    // 14 has 7 as a prime factor
    cout << sol.isUgly(30) << " (Expected: 1)" << endl;    // 30 = 2 × 3 × 5
    cout << sol.isUgly(-6) << " (Expected: 0)" << endl;    // Negative numbers are not ugly

    return 0;
}
