#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int arr[]={4,5,3,1,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    // print 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //traverse
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //         swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }
      
      // bubble sort optimized
    for(int i=0;i<n-1;i++){ // n-1 passes
         //traverse
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
             flag=false;
            }
        }
        if( flag==true){ // swap did not happen
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}