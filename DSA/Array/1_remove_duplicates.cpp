#include <iostream>
#include <vector>
using namespace std;
// brute force
// using hashset
// TC = O(nlogn) + O(n)
// SC = O(n)

// optimal 
// TC = O(n)
// SC = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int uniqueIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[uniqueIdx]) {
                uniqueIdx++;
                nums[uniqueIdx] = nums[i];
            }
        }
        return uniqueIdx + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    Solution sol;
    int newLength = sol.removeDuplicates(nums);

    cout << "After removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
