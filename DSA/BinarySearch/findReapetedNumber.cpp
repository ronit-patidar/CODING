#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,5,6,7};
    int lo=0;
    int hi=8;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid+1) lo=mid+1;
        else if(arr[mid]==mid){
            if(arr[mid-1]==arr[mid]){
                cout<<mid;
                break;
            }
            else hi=mid-1;
        }
    }
}