#include<iostream>
#include<vector>
using namespace std;
// tc = O(nlogn)
// worst O(n*n) when pivot is larger/smaller element in array

// steps
// taking last element as pivot 
// arrange array such that all smaller values than pivot lie on left part and larger values after pivot(left and right part may not be sorted )
// recursively for left and right parts.
int partition(vector<int> &arr,int st,int end){
    int idx=st-1;
    int pivot=arr[end];
    for(int j=st;j<end;j++){
        if(arr[j] < pivot){  // changing > (sort in desending order)
           idx++;
           swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr,int st,int end){
    // if (st>=end) base case 
    if(st < end){
        int pivotIdx=partition(arr,st,end); // place pivot element at its right position
        quickSort(arr,st,pivotIdx-1); // left part
        quickSort(arr,pivotIdx+1,end); // right part 
    }
}
int main() {
    vector<int> arr = {12,31,35,8,32,17};
    quickSort(arr,0,arr.size()-1);
    cout<<"Sorted Array"<<endl;
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    return 0;
}