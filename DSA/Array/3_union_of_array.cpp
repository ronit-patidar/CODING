#include <iostream>
#include <vector>
using namespace std;
// | Approach                        | Time Complexity  | Space Complexity | 
// | ------------------------------- | ---------------- | ---------------- | 
// | **Two-pointer (sorted arrays)** | O(n + m)         | O(n + m)         |
// | **Using `map`**                 | O((n + m) log k) | O(k)             | 
// | **Using `set`**                 | O((n + m) log k) | O(k)             | 

// log k is time complexity of inserting into set/map

// Time Complexity: O(n + m), where n = size of a[], m = size of b[]
// Space Complexity: O(n + m), for storing the result in ans

// why checking always ans.empty❓
// if ans.empty() then we cant access ans back 
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        } 
        else if (a[i] > b[j]) {
            if (ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        } 
        else { // a[i] == b[j]
            if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    while (i < a.size()) {
        if (ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
        j++;
    }

    return ans;
}

// Example usage
int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 6};

    vector<int> result = findUnion(a, b);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
