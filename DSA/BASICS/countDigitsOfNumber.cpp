#include <iostream>

int countDigits(int num) {
    if (num == 0) return 1; // Special case for 0
    int count = 0;
    num = abs(num); // Handle negative numbers
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int num = 12345;
    std::cout << "Digits: " << countDigits(num) << std::endl;
    return 0;
}
