#include<iostream>
#include<vector>
using namespace std;

// SELECTION : HINT-> SELECT SMALLEST ELEMENT FOR EVERY ELEMENT
// Selection Sort Algorithm
// 1. Iterate through the array and select the smallest element in each pass(FOR EVERY ELEMENT).
// 2. Swap the smallest element with the first unsorted position.
// 3. Repeat until the array is sorted.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selectionSort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int smallestIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[smallestIdx]){ // chaning > (sort in desending order)
                smallestIdx=j;
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
}
int main(){
    vector<int> arr={4,1,5,2,3};
    selectionSort(arr);
    for(auto ele:arr){
        cout<<ele<<" ";
    }
}