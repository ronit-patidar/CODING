// leetcode : 650
// link : https://leetcode.com/problems/2-keys-keyboard

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to find the greatest divisor of n less than n
    int gd(int n) {
        for (int i = n / 2; i >= 1; i--) {
            if (n % i == 0) return i;
        }
        return 1;
    }

    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Function to calculate the minimum steps
    int minSteps(int n) {
        int count = 0;
        while (n > 1) {
            if (isPrime(n)) {
                count += n;
                break;
            }
            int hf = gd(n); // Find greatest divisor less than n
            count += (n / hf);
            n = hf;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test cases with expected outputs
    cout << sol.minSteps(1) << " (Expected: 0)" << endl;   // Edge case: no operations needed for 1
    cout << sol.minSteps(2) << " (Expected: 2)" << endl;   // Prime number
    cout << sol.minSteps(3) << " (Expected: 3)" << endl;   // Prime number
    cout << sol.minSteps(4) << " (Expected: 4)" << endl;   // 4 = 2 + 2
    cout << sol.minSteps(6) << " (Expected: 5)" << endl;   // 6 = 3 + 3
    cout << sol.minSteps(10) << " (Expected: 7)" << endl;  // 10 = 5 + 5
    cout << sol.minSteps(15) << " (Expected: 8)" << endl;  // 15 = 3 + 3 + 3 + 3
    cout << sol.minSteps(100) << " (Expected: 14)" << endl; // Composite number
    cout << sol.minSteps(997) << " (Expected: 997)" << endl; // Large prime number
    cout << sol.minSteps(1000) << " (Expected: 21)" << endl; // Large composite number

    return 0;
}
