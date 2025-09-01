#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAllocate(vector<int>& arr, int k, int maxPages) {
        int students = 1, pages = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxPages) return false;
            if (pages + arr[i] > maxPages) {
                students++;
                pages = arr[i];
            } else {
                pages += arr[i];
            }
        }
        return students <= k;
    }

    int findPages(vector<int>& arr, int k) {
        if (k > arr.size()) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAllocate(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int result = sol.findPages(books, students);
    cout << "Minimum possible maximum pages: " << result << endl;

    return 0;
}
