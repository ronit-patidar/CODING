// ⭐

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cstring>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_i

// initialize dp with less than -0.9
double dp[3005][3005];  
double f(vector<double> &p,int i,int x){
  if(x==0) return 1;
  if(i == -1) return 0;
  if(dp[i][x] > -0.9) return dp[i][x];
  return dp[i][x] = f(p,i-1,x-1)*p[i] + f(p,i-1,x)*(1-p[i]);
}
int main() {
  int n;
  cin>>n;
  vector<double> p(n);
  for(int i=0;i<n;i++){ 
    cin>>p[i];
  }
  memset(dp,-1,sizeof dp);

  // 3
  // 0.30 0.60 0.80

  // output -> 0.612
  cout<<fixed<<setprecision(9)<<f(p,n-1,(n+1)/2);

//                   f(2,2)
//               /           \
//          f(1,1)*0.80     f(1,2)*0.20
//          /      \         /      \
// f(0,0)*0.60 f(0,1)*0.40 f(0,1)*0.60 f(0,2)*0.40 
//    |           |           |           |
//    1          0.30        0.30         0


  return 0;
}