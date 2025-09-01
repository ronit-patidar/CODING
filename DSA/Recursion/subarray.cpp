#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
// tc=O(2^n * n)
// sc=O(2^n * n)
void subarrayRecursive(const vector<int> &arr, vector<int> ans, set<vector<int>> &uniqueSubarrays, int idx) {
    if(idx == arr.size()) {
        uniqueSubarrays.insert(ans);
        return;
    }
    
    // Exclude current element
    subarrayRecursive(arr, ans, uniqueSubarrays, idx+1);
    
    // Include current element without backtracking
    ans.push_back(arr[idx]);
    subarrayRecursive(arr, ans, uniqueSubarrays, idx+1);
}

void print(const vector<vector<int>>& subarrays) {
    for(const auto &sub : subarrays) {
        for(int num : sub) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2}; // Example with duplicates
    sort(arr.begin(), arr.end()); // Sorting to maintain lexicographical order
    
    set<vector<int>> uniqueSubarrays;
    vector<int> ans;
    subarrayRecursive(arr, ans, uniqueSubarrays, 0);
    
    vector<vector<int>> result(uniqueSubarrays.begin(), uniqueSubarrays.end());
    print(result);
}
