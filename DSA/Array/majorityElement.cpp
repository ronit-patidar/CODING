#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ele = nums[i];
        int cnt = 1;
        int j = i + 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                cnt++;
                j++;
            } else {
                cnt--;
                j++;
            }
            if (cnt == 0) {
                i = j;
                if (i < n) {
                    cnt = 1;
                    j = i + 1;
                    ele = nums[i];
                }
            }
        }
        return ele;
    }
};

int main() {
    vector<int> nums = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    Solution sol;
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
