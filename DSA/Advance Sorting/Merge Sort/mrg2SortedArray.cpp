#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){ 
        res[k++]=a[i++];
        }
        else // a[i]>b[j]
        res[k++]=b[j++];
    }
    if(i==a.size()){
        while(j<b.size()){
        res[k++]=b[j++];
    }
    }
    if(j==b.size()){
        while(i<a.size()){
        res[k++]=a[i++];
    }
    }
}
int main(){
    // int arr1[]={1,4,5,8}; // sorted array 1
    // int arr2[]={2,3,6,7,10,12}; // sorted array 2
    int arr1[]={1,2,4,6,10,12,14,19,20,21};
    int arr2[]={2,6,9,12,13,15,18};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    vector<int> a(arr1,arr1+n1);
    vector<int> b(arr2,arr2+n2);
    vector<int> res(n1+n2);
    merge(a,b,res);
    for(int i=0;i<res.size();i++){
       cout<<res[i]<<" ";
    }
}
