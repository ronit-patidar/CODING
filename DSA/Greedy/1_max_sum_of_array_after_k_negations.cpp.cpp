#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// maximize sum of array after k negation
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Use a min-heap (priority_queue with greater<int>) to keep track of smallest element
        priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.end()); // O(n)
        int sum = 0;

        // Compute the initial sum
        for (auto ele : nums) sum += ele; // O(n)

        // Perform k negations
        while (k--) { // k negations, each pop and push in O(logn)
            int ele = pq.top();
            pq.pop(); // Remove the smallest element
            
            // Negate the smallest element
            sum -= ele; // Subtract the smallest element from sum
            pq.push(-1 * ele); // Add the negated number back into the heap
            sum += (-ele); // Add the negated element to the sum

            // If the smallest element is 0, no more negations will make a difference
            if (ele == 0) {
                break;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {2,-3,-1,5,-4};
    int k = 2;
    Solution sol;
    int result = sol.largestSumAfterKNegations(nums, k);
    cout << "Largest sum after " << k << " negations: " << result << endl;
    return 0;
}
