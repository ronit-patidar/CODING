#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// heap sort can be done through minheap and maxheap
int main() {
    // tc = O(nlogn) just like merge sort    
    // sc = O(n)
    vector<int> arr={2,6,4,5,1,3};
    priority_queue< int,vector<int>,greater<int> > pq;
    for(auto ele:arr){  
        pq.push(ele);
    }
    int idx=0;
    while(!pq.empty()){
        arr[idx++]=pq.top();
        pq.pop();
    }
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    return 0;
}