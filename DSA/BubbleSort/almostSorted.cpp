#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
     int arr[]={1,2,3,5,4};
     int n=sizeof(arr)/sizeof(arr[0]);

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;

     for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            i++;
        }
        }
        bool flag=true;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
           flag=false;
        }

        }
        if(flag==true) cout<<"almost sorted";
                else cout<<"no ";
     
    }