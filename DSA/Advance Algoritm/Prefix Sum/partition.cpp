#include<iostream>
using namespace std;
int main(){
    int arr[]={5,10,15,8,2,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    // making original array to prefix sum array

    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }

    // finding partition element
    int idx=-1;
    for(int i=1;i<n;i++){
        if(2*arr[i]==(arr[n-1])){
             idx=i;
             break;
        }
    }
    if(idx!=-1) cout<<"partition element at "<<idx;
    else cout<<" no partition element  ";
}