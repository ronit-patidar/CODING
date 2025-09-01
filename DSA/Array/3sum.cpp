// https://leetcode.com/problems/3sum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// this will work if array is sorted 
// optimized solution
//  O(n^2),O(n^2) 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        // Step 1: Sort the input array to easily handle duplicates
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Iterate through each element as the first element of a triplet
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Use two-pointer approach for the remaining elements
            int j = i + 1;  // Second element
            int k = n - 1;  // Third element

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    // If sum is less than 0, move `j` right to increase sum
                    j++;
                } else if (sum > 0) {
                    // If sum is greater than 0, move `k` left to decrease sum
                    k--;
                } else {
                    // If sum is exactly 0, store the triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers to check for next valid triplet
                    j++;
                    k--;

                    // Skip duplicate `j` values to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    
                    // Skip duplicate `k` values to avoid duplicate triplets
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example input array
    vector<int> nums = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
    
    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    // Print the result
    cout << "Unique Triplets with sum 0:\n";
    for (const auto& triplet : result) {
        cout << "{";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "}\n";
    }

    return 0;
}