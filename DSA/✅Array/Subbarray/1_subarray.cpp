// A **subarray** is a contiguous (continuous) part of an array.

// ### Key Points:

// * The elements of a subarray are **next to each other** in the original array.
// * The order of elements stays the same.
// * An array of size `n` has `n*(n+1)/2` possible subarrays.

// ---

// ### Example:

// For array: `arr = [1, 2, 3]`

// **All possible subarrays are:**

// * `[1]`
// * `[1, 2]`
// * `[1, 2, 3]`
// * `[2]`
// * `[2, 3]`
// * `[3]`

// ---

// ### Not a Subarray:

// * `[1, 3]` is **not** a subarray because 1 and 3 are not next to each other in the original array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int arr[]={1,2,3};
    for(int i=0;i<3;i++){
      for(int j=i;j<3;j++){
        cout<<"[ ";
        for(int k=i;k<=j;k++){
          cout<<arr[k];
          if(k!=j){
            cout<<",";
          }
        }
        cout<<" ]";
        cout<<endl;
      }
    }
    return 0;
}