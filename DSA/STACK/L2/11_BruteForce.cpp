#include<iostream>
using namespace std;

int main(){
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    // output should be: 5, 2, 5, 6, 6, -1, 3, -1
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];

    for(int i = 0; i < n; i++) {
        ans[i] = -1;  // Initialize with -1 assuming no greater element
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;  // Only assign the first greater element
            }
        }
    }

    for(auto ele : ans) {
        cout << ele << " ";
    }

    return 0;
}
