// leetcode no : 1207
// link : https://leetcode.com/problems/unique-number-of-occurrences
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n= arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++; // automaticaly increase frequency
        }
        unordered_set<int> s;
        for(auto x : m){
            int freq=x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> arr={1,2,2,1,1,3};
    cout<<sol.uniqueOccurrences(arr)<<endl; // expected output : true
    return 0;
}