// brute fore approach
#include<iostream>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;  // subarray size
    int maxsum=0;
    int maxIdx=0;
    for(int i=0;i<=n-k;i++){
    int sum=0;
        for(int j=i;j<i+k;j++){
           sum  += arr[j];
        }
        maxsum=max(sum,maxsum);
    }
    std::cout<<maxsum<<endl;
    std::cout<<maxIdx;
}