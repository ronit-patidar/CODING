#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,4,5,9,15,18,21,24};
    int x=20;
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    bool flag = false; // element can be in array or not be if it in array
     //when loop wile be true otherwise loop will be false
    while(lo<=hi){
    int mid=(hi+lo)/2;
        if(arr[mid]==x) {
            flag=true;
            cout<<arr[mid-1]; // - for lower & + for upper
            break;
        }
        else if(arr[mid]<x) lo=mid+1;
        else  hi=mid-1;
    }
    if(flag==false) cout<<arr[lo];
    //hi lower bound 
    //lo upper bound
}