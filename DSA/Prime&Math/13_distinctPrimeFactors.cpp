// leetcode : 2521
// link : https://leetcode.com/problems/distinct-prime-factors-of-product-of-array
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    void fillSeive(vector<bool>& seive) {
        int n = seive.size() - 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (seive[i]) {
                for (int j = i * i; j <= n; j += i) {
                    seive[j] = 0;
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
        }

        vector<bool> seive(maxi + 1, 1); // Mark all as prime initially
        if (maxi + 1 > 0) seive[0] = 0;
        if (maxi + 1 > 1) seive[1] = 0;
        fillSeive(seive);

        vector<int> primes;
        for (int i = 2; i <= maxi; i++) {
            if (seive[i]) primes.push_back(i);
        }

        vector<bool> taken(primes.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            for (int j = 0; j < primes.size(); j++) {
                if (primes[j] > ele) break;
                if (ele % primes[j] == 0) taken[j] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < taken.size(); i++) {
            if (taken[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {2, 3, 4, 5}; // Distinct primes: 2, 3, 5
    cout << sol.distinctPrimeFactors(nums1) << endl; // Expected: 3

    vector<int> nums2 = {6, 10, 15}; // Distinct primes: 2, 3, 5
    cout << sol.distinctPrimeFactors(nums2) << endl; // Expected: 3

    vector<int> nums3 = {1, 1, 1}; // No primes
    cout << sol.distinctPrimeFactors(nums3) << endl; // Expected: 0

    vector<int> nums4 = {29, 30, 77}; // Distinct primes: 2, 3, 5, 7, 11, 29
    cout << sol.distinctPrimeFactors(nums4) << endl; // Expected: 6

    vector<int> nums5 = {2}; // Only one prime: 2
    cout << sol.distinctPrimeFactors(nums5) << endl; // Expected: 1

    vector<int> nums6 = {100, 200, 300}; // Distinct primes: 2, 3, 5
    cout << sol.distinctPrimeFactors(nums6) << endl; // Expected: 3

    return 0;
}
