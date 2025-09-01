#include <iostream>
using namespace std;

void print1ToN(int n) {
    if (n == 0) return;          // base case
    print1ToN(n - 1);            // recursive call
    cout << n << " ";            // print after recursion to maintain order
}

int main() {
    int n = 5;
    print1ToN(n);
    return 0;
}
