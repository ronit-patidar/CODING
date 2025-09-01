#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the k-th symbol in the n-th row of the grammar
    int kthGrammar(int n, int k) {
        // Base case: The first row is just '0'
        if (n == 1) return 0;

        // If k is even, the current symbol is the opposite of the (k/2)th symbol in the previous row
        if (k % 2 == 0) {
            return 1 - kthGrammar(n - 1, k / 2);
        }
        // If k is odd, it's the same as the ((k+1)/2)th symbol in the previous row
        else {
            return kthGrammar(n - 1, (k + 1) / 2);
        }
    }
};

int main() {
    Solution sol;

    int n = 4; // Example: 4th row
    int k = 5; // Example: 5th symbol in the 4th row

    int result = sol.kthGrammar(n, k);

    cout << "The " << k << "-th symbol in row " << n << " is: " << result << endl;

    return 0;
}
