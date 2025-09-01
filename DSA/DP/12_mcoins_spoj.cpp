#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, l, m;
    cin >> k >> l >> m;
    
    vector<int> dp(1000001, 0);  // 0: losing, 1: winning

    for (int i = 1; i < dp.size(); i++) {
        // if any move (i-1, i-k, i-l) leads to a losing state, mark current as winning
        if (i - 1 >= 0 && dp[i - 1] == 0) dp[i] = 1;
        else if (i - k >= 0 && dp[i - k] == 0) dp[i] = 1;
        else if (i - l >= 0 && dp[i - l] == 0) dp[i] = 1;
        // else, it stays 0 (losing)
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << (dp[num] ? "A" : "B");
    }

    return 0;
}
