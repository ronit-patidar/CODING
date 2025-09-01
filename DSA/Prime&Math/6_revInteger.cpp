#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

#include <iostream>
#include <cmath>    // maths
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int reverse(int num) {
        int n = abs(num); // Work with the absolute value
        int revNum = 0;

        while (n != 0) {
            int digit = n % 10;

            // Check for overflow/underflow
            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && digit > 7)) {
                return 0; // Overflow
            }

            revNum = (revNum * 10) + digit; // Add the digit to the reversed number
            n /= 10; // Remove the last digit from n
        }

        // Restore the sign if the number was negative
        return num < 0 ? -revNum : revNum;
    }
};

int main() {
    Solution sol;

    // Example Test Outputs
    cout << sol.reverse(1234) << endl;      // Expected: 4321
    cout << sol.reverse(-4567) << endl;     // Expected: -7654
    cout << sol.reverse(1200) << endl;      // Expected: 21
    cout << sol.reverse(-9) << endl;        // Expected: -9
    cout << sol.reverse(0) << endl;         // Expected: 0
    cout << sol.reverse(2147483647) << endl; // Expected: 0 (overflow)
    cout << sol.reverse(-2147483648) << endl; // Expected: 0 (underflow)

    return 0;
}
