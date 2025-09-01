#include <iostream>
#include <vector>
using namespace std;
// combination 1
// c2
// generate parenthesis
class Solution {
public:
    void genrateParenthesis(string ans,int open,int close,int n) {
        if(close==n){
            cout<<ans<<endl;
            return ;
        }
        if(open<n) genrateParenthesis(ans+'(',open+1,close,n);
        if(close<open) genrateParenthesis(ans+')',open,close+1,n);
    }
};

int main() {
    Solution sol;
    int n=2;
    sol.genrateParenthesis("",0,0,n);
}