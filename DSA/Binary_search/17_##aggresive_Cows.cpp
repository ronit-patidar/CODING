#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int> &stalls, int k, int dis) {
        int cntCows = 1;
        int last = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= dis) {
                last = stalls[i];
                cntCows++;
            }
        }
        return cntCows >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int st = 1;
        int end = stalls.back() - stalls[0];
        int ans = 0;

        for (int i = st; i <= end; i++) {
            if (canPlace(stalls, k, i)) {
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example Input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3; // number of cows

    int result = sol.aggressiveCows(stalls, k);
    cout << "Maximum minimum distance = " << result << endl;

    return 0;
}
