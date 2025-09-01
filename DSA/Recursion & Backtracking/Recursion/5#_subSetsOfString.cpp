#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Tc = O(2^n * n)
//  Sc = O(2^n * n)
void subsets(vector<string> &v, string str, string ans, int idx) {

    if(idx == str.size()) { // base case
        v.push_back(ans);
        return;
    }

    subsets(v, str, ans + str[idx], idx + 1); // include

    // Skip all consecutive duplicates
    while(idx + 1 < str.size() && str[idx] == str[idx + 1]) {
        idx++; // skip over duplicates
    }

    subsets(v, str, ans, idx + 1);  // exclude 
}

int main() {
    string str = "aba";

    sort(str.begin(), str.end());  // Sort the string so duplicates are adjacent

    vector<string> v;  // Vector to store all subsets

    subsets(v, str, "", 0); // Generate subsets

    sort(v.begin(), v.end());  // Sort subsets to lexicographically

    // Step 4: Print subsets
    for(auto s : v) {
        cout << s << " ";
    }
}

/*
==========================================
| Approach         | Deduplication Way            | Time Complexity              | Space Complexity         |
|------------------|------------------------------|------------------------------|---------------------------|
| Brute Force      | Generate all, remove later   | O(2^n * n + 2^n log(2^n))    | O(2^n * n)                |
| Better           | Skip duplicates during recursion | O(2^n * n)              | O(2^n * n)                |
| Optimal          | Use set to handle duplicates | O(2^n * n log(2^n))          | O(2^n * n) (set)          |
==========================================
Notes:
- n = length of input string.
- 2^n subsets possible for n characters.
- If you only want unique & sorted subsets, 'set' is the cleanest.
- 'Better' approach is interview-friendly and avoids extra data structures.
*/

