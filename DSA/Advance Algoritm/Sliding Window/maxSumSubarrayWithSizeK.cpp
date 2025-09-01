#include<iostream>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;  // subarray size
    int maxsum=INT16_MIN;  // to stor max sum
    int maxIdx=0;          // to stor index to subarray
    int sum=0;             // to calculate sum of subarray for compairing
    for(int i=0;i<k;i++){   // calculating sum of first subarray
        sum+=arr[i];
    }
    maxsum=sum;             // max sum till now
    // sliding window
    int i=1;   // st idx
    int j=k;   // end idx
    while(j<n){
        sum=sum+arr[j]-arr[i-1]; 
        if(maxsum<sum){
            maxsum=sum;
            maxIdx=i;
        }
        i++;
        j++;
    }
    // tc O(n)
    cout<<"Max sum "<<maxsum<<endl;
    cout<<"Starting Idx "<<maxIdx;
}