// https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

// C++ recursive function to
// solve tower of hanoi puzzle

//  tc = O(2^N)
//  sc = O(N)

// Algorithm of code .

// Move (n-1) disks to helper 
// last disk from source to destination
// Move (n-1) disks from helper to destination.

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper) {
    if (n == 0) return;
    towerOfHanoi(n - 1, source, helper, destination);
    cout << source << " -> " << destination << endl;
    towerOfHanoi(n - 1, helper, destination, source);
}

int main() {
    int n = 2;
    towerOfHanoi(n, 'A', 'C', 'B');
}
