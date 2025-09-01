//  leetcode 125
// https://leetcode.com/problems/valid-palindrome
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // Output: 1 (true)
    cout << sol.isPalindrome("race a car") << endl; // Output: 0 (false)
    return 0;
}
