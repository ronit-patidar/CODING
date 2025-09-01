#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
       int arr[]={4,5,3,1,2};
       int n=sizeof(arr)/sizeof(arr[0]);

       for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
       }
       cout<<endl;

       for(int i=0;i<n-1;i++){
         bool flag = true;
           for(int j=0;j<i+1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
           }
        if(flag==true){//swap didnot happen
            break;
        }
       }

       for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
       }
    }