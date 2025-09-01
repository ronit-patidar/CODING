#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2

int main() {
  int n;
  cin>>n;
  vector<int> f(n+1,0); // 1 based indexing 0 index dummy
  int m;
  cin>>m;
  vector<int> l(n+1,0);
  vector<int> r(n+1,0);
  for(int i=0;i<m;i++){
      int L,R; // indexes
      cin>>L>>R;
      l[L]++;
      r[R]++;
  }
  f[1]=l[1];
  for(int i=2;i<=n;i++){
      f[i] = l[i] - r[i-1] + f[i-1];
  }
  vector<int> c(10000005, 0);
  for(int i=0;i<=n;i++){
    int coins = f[i];
    c[coins]++;
  }
  for(int i=c.size()-2;i>=0;i--){ // suffix sum
    c[i] += c[i+1];
  }
  int q;
  cin>>q;
  vector<int> ans;
  while(q--){
    int num;
    cin>>num;
    // cout<<c[num]<<endl; // causing ambiguity in vs code 
    ans.push_back(c[num]);
  }  
  cout<<endl<<"ans :"<<endl;
  for(auto ele:ans){
    cout<<ele<<endl;
  }
  return 0;
}