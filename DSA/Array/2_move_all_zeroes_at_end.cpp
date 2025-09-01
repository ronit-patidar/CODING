#include <iostream>
#include <vector>
using namespace std;

// TC = O(n)
// SC = O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;  // Points to the next position to place non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};
int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(arr);
    for(auto elem:arr){
        cout<<elem<<" ";
    }
}
