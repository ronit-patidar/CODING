#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// Subarray -> a subarray is a contigous part of array.
// TC = O(n^3)
// SC = O(1)
int main() {
    vector<int> a={2,3,5};
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}