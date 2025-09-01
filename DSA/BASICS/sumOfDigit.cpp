#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    while (number != 0) {
        sum += number % 10;   // Add the last digit to sum
        number /= 10;         // Remove the last digit
    }
    
    cout << "Sum of digits: " << sum << endl;
    return 0;
}



