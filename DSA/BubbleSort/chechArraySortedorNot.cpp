#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,5,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    //traverse
     bool flag=true;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                flag = false;
                break;
            }
        }
    if(flag==true) cout<<"sorted";
      else cout<<"not sorted";
    }