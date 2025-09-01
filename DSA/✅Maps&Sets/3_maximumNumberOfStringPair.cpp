// leetcode no : 2744
// link : https://leetcode.com/problems/find-maximum-number-of-string-pairs
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 2nd method
class Solution1 {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int count=0;
        int n=arr.size();
        unordered_set<string> s;
        for(int i=0;i<n;i++){ // O(n)
            // insert in set
            s.insert(arr[i]);
        }
        for(int i=0;i<n;i++){ // O(n)
            string rev = arr[i];
            reverse(rev.begin(),rev.end()); //rev string
            if(rev==arr[i]) continue; // palindrome cant be pair
            if(s.find(rev)!=s.end()){// pair exist // O(1)
                count++;
                s.erase(arr[i]); //delete 
                // prevent counting the same pair multiple times.
            }
        }
        return count;
    }
};
// 1nd method O(n)
class Solution {
public:     
     string reverse(string str){
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            string rev = reverse(words[i]);
            for(int j=i+1;j<n;j++){
                if(words[j]==rev) count++;
            }
        }   
        return count;
    }
};
// 3rd method 
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        unordered_set<string> s;
        int count=0;
        for(int i=0;i<n;i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)==s.end()){ // not found then insert
                s.insert(words[i]);
            }
            else count++; // found then count++
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<string> arr1 = {"cd", "ac", "dc", "ca", "zz"};
    cout << sol.maximumNumberOfStringPairs(arr1) << endl; // Expected output: 2
    return 0;
}
