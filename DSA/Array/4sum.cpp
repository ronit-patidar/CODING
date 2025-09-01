#include <bits/stdc++.h>
using namespace std;
// tc = O(n^3)
// sc = O(1)
int fourSumCount(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;
    sort(nums.begin(), nums.end()); // Step 1: Sort the array

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate `i`

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate `j`

            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum < target) {
                    k++;
                } 
                else if (sum > target) {
                    l--;
                } 
                else {
                    count++; // Found a valid quadruplet
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1]) k++; // Skip duplicate `k`
                    while (k < l && nums[l] == nums[l + 1]) l--; // Skip duplicate `l`
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
    int target = 0;
    cout << "Number of quadruplets: " << fourSumCount(arr, target) << endl;
    return 0;
}
