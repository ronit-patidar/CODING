#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//  Tc = O(2^n * n)
//  Sc = O(2^n * n)
void subsetsOfArray(vector<int> arr, vector<int> ans, vector<vector<int>>& res, int idx) {
    if (idx == arr.size()) { // base case 
        res.push_back(ans);
        return;
    }
    subsetsOfArray(arr, ans, res, idx + 1); // exclude element 
    ans.push_back(arr[idx]);
    while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) { // to skip duplicates 
        idx++;
        ans.push_back(arr[idx]);
    }
    subsetsOfArray(arr, ans, res, idx + 1); // include element 
}

int main() {
    vector<int> arr = {1, 2, 1};  // works for both duplicates and unique elements 
    sort(arr.begin(), arr.end());  // Sort the array so duplicates are adjacent

    vector<int> ans;  // vector to generate subsets
    vector<vector<int>> res; // 2d vector to store subsets

    subsetsOfArray(arr, ans, res, 0);  // generate subsets

    sort(res.begin(), res.end()); // sort subsets lexicographically

    // printing subsets
    for (auto &row : res) {
        cout << "{";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i != row.size() - 1) cout << ",";
        }
        cout << "} ";
    }
}

/*
==========================================
| Approach         | Deduplication Way            | Time Complexity              | Space Complexity         | Pros                                     |
|------------------|------------------------------|------------------------------|---------------------------|------------------------------------------|
| Brute Force      | Generate all, remove later   | O(2^n * n + 2^n log(2^n))    | O(2^n * n)                | Simple, straightforward logic           |
| Better           | Skip duplicates during recursion | O(2^n * n)              | O(2^n * n)                | Efficient, no extra post-processing     |
| Optimal          | Use set to handle duplicates | O(2^n * n log(2^n))          | O(2^n * n) (set)          | Clean, concise, automatically handles uniqueness |
==========================================
Notes:
- n = length of input array.
- 2^n subsets possible for n elements.
- Copying subsets is O(n) per subset.
- 'Better' avoids the need for post-processing with sorting or set.
*/

