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
    vector<int> arr = {1, 1, 2};  // works for both duplicates and unique elements 
    sort(arr.begin(), arr.end()); // sort original array

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
