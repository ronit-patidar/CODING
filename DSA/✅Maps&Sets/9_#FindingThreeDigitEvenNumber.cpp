// leetcode no : 2094
// link : https://leetcode.com/problems/finding-3-digit-even-numbers
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for (int ele : digits){ // filled map with freq
            m[ele]++;
        }
        for(int i=100;i<=999;i+=2){
            int x=i;
            int a = x%10; // once digit
            x=x/10;
            int b = x%10; // tense digit
            x=x/10;
            int c=x; // hundred digit
            if(m.find(a)!=m.end()){
                m[a]--; // decrese frequency
                if(m[a]==0) m.erase(a);

                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);

                if(m.find(c)!=m.end())  ans.push_back(i);
                m[b]++; // insert b
                }
                m[a]++; // insert a
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> digits = {2, 1, 3, 0};
    vector<int> result = sol.findEvenNumbers(digits);

    // Output the results
    cout<<"Expected : [102,120,130,132,210,230,302,310,312,320] ";
    cout << "Even numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
