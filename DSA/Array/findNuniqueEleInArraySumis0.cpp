// leetcode : 1304
// link : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2 == 1) result.push_back(0);
        return result;
    }
};

// Function to print the vector
void printVector(const vector<int>& v) {
    for (int num : v) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> result = sol.sumZero(6);

    cout << "Result: ";
    printVector(result);

    return 0;
}
