#include <iostream>
#include <cmath> // For pow() function

using namespace std;

/*
 * Armstrong Number (Narcissistic Number):
 * A number is called an Armstrong number if the sum of its digits 
 * raised to the power of the number of digits equals the number itself.
 * 
 * Example:
 *  - 153 → (1^3) + (5^3) + (3^3) = 1 + 125 + 27 = 153 (Armstrong)
 *  - 9474 → (9^4) + (4^4) + (7^4) + (4^4) = 9474 (Armstrong)
 *  - 123 → (1^3) + (2^3) + (3^3) = 36 (Not Armstrong)
 */

bool isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;

    // Count the number of digits
    int temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Compute sum of digits raised to the power of 'digits'
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (isArmstrong(n))
        cout << n << " is an Armstrong number.\n";
    else
        cout << n << " is not an Armstrong number.\n";

    return 0;
}
