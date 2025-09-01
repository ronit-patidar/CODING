#include<iostream>
using namespace std;
// In array every element occur twice execpt one element find that element
int main(){
    int arr[]={1,2,1,10,2,9,10,9,69};
    int n = 9;
    int res=0;
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    cout<<"Unique element : "<<res;
}
