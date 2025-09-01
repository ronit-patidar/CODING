#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) { //O(n) //O(sort)
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int bt = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                bt++;  // allocate boat to pair
                i++;
                j--;
            }
            else {
                j--;  // allocate boat to heaviest
                bt++;
            }
        }
        return bt;
    }
};

int main() {
    Solution solution;
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << "Number of boats required: " << solution.numRescueBoats(people, limit) << endl;
    return 0;
}
