#include<iostream>
using namespace std;
int main(){
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    // output should be: -1,3,3,-1,5,-1,6,6
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];
    // RIGHT TO LEFT

    for(int i=n-1;i>=0;i--){
        ans[i]=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]<arr[j]) {
                ans[i]=arr[j];
                break;
            }
        }
    }

    // LEFT TO RIGHT
    // ans[0]=-1;
    // for(int i=1;i<n;i++){
    //     ans[i]=-1;
    //     for(int j=i-1;j>=0;j--){
    //         if(arr[j]>arr[i]){
    //             ans[i]=arr[j];
    //             break;
    //         }
    //     }
    // }
    for(auto ele : ans) {
        cout << ele << " ";
    }
    return 0;
}
