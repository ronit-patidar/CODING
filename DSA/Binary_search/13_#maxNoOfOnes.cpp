#include <iostream>
#include <vector>
using namespace std;

// brute O(mn) O(1)
// optimal O(mlogn) O(1)

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int m = arr.size();
        int n = arr[0].size();
        int index = -1;
        int cnt_max = -1; 
        for (int i = 0; i < m; i++) {
            int cnt = n - lowerBound(arr[i], 1);
            if (cnt > cnt_max) {
                cnt_max = cnt;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };
    
    int result = sol.rowWithMax1s(arr);
    cout << "Row with maximum 1s: " << result << endl;
    
    return 0;
}
