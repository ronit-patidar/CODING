#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

int main() {
  int n;
  cin>>n;
  vector<int> f(n+10,0); // 1 based indexing 0 index dummy
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
      int L,R; // indexes
      cin>>L>>R;
      f[L]++;
      f[R+1]--;
  }
  for(int i=1;i<f.size();i++){
    f[i] += f[i-1];
  }
  vector<int> c(10000005, 0);
  for(int i=1;i<=n;i++){
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