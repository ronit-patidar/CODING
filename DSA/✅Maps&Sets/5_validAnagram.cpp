// leetcode : 242
// link : https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
// method 1 (using one map) optimized
class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> map1; // for s
    for(int i=0;i<s.size();i++){
        map1[s[i]]++; // char and frequency
    }
    for(int i=0;i<t.size();i++){
        char ch=t[i];
        if(map1.find(ch)!=map1.end()){
            map1[ch]--; // decrease frequency
            if(map1[ch]==0) map1.erase(ch); // remove if frequency is 0
        }
        else return false; // if char not found return false
    }
    if(map1.size()>0) return false;
    return true;
    }
};
// method 2 (using two map)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> map1; // for s
    unordered_map<char,int> map2;  // for t
    for(int i=0;i<s.size();i++){
        map1[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        map2[t[i]]++;
    }
    for(auto x: map1){
        char ch1 = x.first;
        int freq1 = x.second;
        if(map2.find(ch1)!=map2.end()){
            int freq2 = map2[ch1];
            if(freq1!=freq2) return false;
        }
        else return false;
    }
        return true;
    }
};
// method 3 (using sort)
class Solution3 {
public:
    bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) return true;
    else return false;
    }
};
int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout<<sol.isAnagram(s,t)<<endl; // Expected output: 1
}