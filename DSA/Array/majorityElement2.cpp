#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1, el2;  // Initial values, updated dynamically

        for (int num : nums) {
            if (cnt1 == 0 && num != el2) {
                el1 = num;
                cnt1 = 1;
            } 
            else if (cnt2 == 0 && num != el1) {
                el2 = num;
                cnt2 = 1;
            } 
            else if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Second pass to verify counts
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            if (num == el2) cnt2++;
        }

        vector<int> ans;
        int threshold = n / 3;
        if (cnt1 > threshold) ans.push_back(el1);
        if (cnt2 > threshold && el1 != el2) ans.push_back(el2);

        return ans;
    }  
};

int main() {
    Solution sol;
    
    vector<int> testCase = {1,1,1,1,3,2,2,2};  // Single test case
    vector<int> result = sol.majorityElement(testCase);

    cout << "\nOutput: ";
    for (int num : result) cout << num << " ";
    
    cout << endl;
    return 0;
}