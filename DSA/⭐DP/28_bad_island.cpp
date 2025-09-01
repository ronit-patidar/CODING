#include <iostream>
#include <iomanip>
#include <string.h>
#define ll long long
#define ld long double
using namespace std;
ld dp[105][105][105];

// prob of rock survival
ld fr(int r, int s, int p) {
    if (r == 0 || s == 0) return 0.0;
    if (p == 0) return 1.0;
    if (dp[r][s][p] > -0.5) return dp[r][s][p];
    ld total = r * s + s * p + p * r;
    ld result = 0.0;
    if (r > 0 && p > 0)
        result += fr(r - 1, s, p) * ((r * p) / total);
    if (r > 0 && s > 0)
        result += fr(r, s - 1, p) * ((r * s) / total);
    if (s > 0 && p > 0)
        result += fr(r, s, p - 1) * ((s * p) / total);
    return dp[r][s][p] = result;
}

// prob of scissors survival
ld fs(int r, int s, int p) {
    if (s == 0 || p == 0) return 0.0;
    if (r == 0) return 1.0;
    if (dp[r][s][p] > -0.5) return dp[r][s][p];
    ld total = r * s + s * p + p * r;
    ld result = 0.0;
    if (r > 0 && p > 0)
        result += fs(r - 1, s, p) * ((r * p) / total);
    if (r > 0 && s > 0)
        result += fs(r, s - 1, p) * ((r * s) / total);
    if (s > 0 && p > 0)
        result += fs(r, s, p - 1) * ((s * p) / total);
    return dp[r][s][p] = result;
}

// prob of paper survival
ld fp(int r, int s, int p) {
    if (r == 0 || p == 0) return 0.0;
    if (s == 0) return 1.0;
    if (dp[r][s][p] > -0.5) return dp[r][s][p];
    ld total = r * s + s * p + p * r;
    ld result = 0.0;
    if (r > 0 && p > 0)
        result += fp(r - 1, s, p) * ((r * p) / total);
    if (r > 0 && s > 0)
        result += fp(r, s - 1, p) * ((r * s) / total);
    if (s > 0 && p > 0)
        result += fp(r, s, p - 1) * ((s * p) / total);
    return dp[r][s][p] = result;
}

int main() {
    ll r, s, p;
    cin >> r >> s >> p;
    memset(dp, -1, sizeof dp);
    ld ans_r = fr(r, s, p);
    memset(dp, -1, sizeof dp);
    ld ans_s = fs(r, s, p);
    memset(dp, -1, sizeof dp);
    ld ans_p = fp(r, s, p);
    cout << fixed << setprecision(9) << ans_r << " " << ans_s << " " << ans_p;
    return 0;
}