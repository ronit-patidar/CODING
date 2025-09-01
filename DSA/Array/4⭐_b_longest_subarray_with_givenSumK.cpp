#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// Subarray -> a subarray is a contigous part of array.

// TC = O(n^3)
// SC = O(1)
void brute_subarray_len(vector<int> &a,int tar){
    int n=a.size();
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long  sum=0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            if(sum == tar){
                len = max(len,j-i+1);
            }
            cout<<endl;
        }
    }
    cout << "Maximum subarray length with target sum " << tar << " is " << len << ".\n";
}
// TC = O(n^2)
// SC = O(1)
void better_subarray_len(vector<int> &a,int tar){
    int n=a.size();
    int len=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(tar == sum){
                len=max(len,j-i+1);
            }
        }
    }
    cout << "Maximum subarray length with target sum " << tar << " is " << len << ".\n";
}
// ⭐
// | i  | a\[i] | prefixSum | prefixSum - tar | `mp` lookup | Action                                            | len |
// | -- | ----- | --------- | --------------- | ----------- | ------------------------------------------------- | --- |
// | 0  | 0     | 0         | -3              | ❌           | prefixSum == tar? ❌; insert 0 → 0                 | 0   |
// | 1  | 0     | 0         | -3              | ❌           | Already in map → skip                             | 0   |
// | 2  | 1     | 1         | -2              | ❌           | insert 1 → 2                                      | 0   |
// | 3  | 0     | 1         | -2              | ❌           | already in map → skip                             | 0   |
// | 4  | 2     | 3         | 0               | ✅ 0         | prefixSum == tar ✅ → len = 5, also i - mp\[0] = 4 | 5   |
// | 5  | 0     | 3         | 0               | ✅ 0         | already in map → len = max(5, 5 - 0) = 5          | 5   |
// | 6  | 0     | 3         | 0               | ✅ 0         | already in map → len = max(5, 6 - 0) = 6          | 6   |
// | 7  | 3     | 6         | 3               | ✅ 4         | len = max(6, 7 - 4) = 6                           | 6   |
// | 8  | 0     | 6         | 3               | ✅ 4         | len = max(6, 8 - 4) = **4** (less) → len stays 6  | 6   |
// | 9  | -1    | 5         | 2               | ❌           | insert 5 → 9                                      | 6   |
// | 10 | 0     | 5         | 2               | ❌           | already in map → skip                             | 6   |
// | 11 | 0     | 5         | 2               | ❌           | already in map → skip                             | 6   |

void optimal_subarray(vector<int> &a,int tar){ // works on array containg -ve,0,+ve element
    int n=a.size();
    int len=0;
    unordered_map<int,int> mp;
    int prefixSum=0;
    for(int i=0;i<n;i++){
        prefixSum += a[i];
        if(tar == prefixSum){
            len = max(len,i+1);
        }
        long long rem=prefixSum-tar;
        if(mp.find(rem) != mp.end()){
            len = max(len,i-mp[rem]);
        }
        // if subbarray is already present then no need to update subbarray lenght because we want max len k sum subbarray.
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }
    cout << "Maximum subarray length with target sum " << tar << " is " << len << ".\n";
}
int main() {
    vector<int> a={0, 0, 1, 0, 2, 0, 0, 3, 0, -1, 0, 0};
    brute_subarray_len(a,5);
    cout<<endl; 
    better_subarray_len(a,5);
    cout<<endl;
    optimal_subarray(a,5);
    return 0;
}