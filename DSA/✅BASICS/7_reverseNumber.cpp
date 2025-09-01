#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int reverse = 0;
    while (n != 0) {
        int digit = n % 10;  // Get the last digit
        reverse = reverse * 10 + digit;  // Append the digit
        n /= 10;  // Remove the last digit
    }
    return reverse;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int reversed = reverseNumber(number);
    cout << "Reversed number: " << reversed << endl;

    return 0;
}
