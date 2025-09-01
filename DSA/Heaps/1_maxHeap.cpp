#include<iostream>
#include<queue>
using namespace std;
int main(){
    // MAX HEAP

    // time complexity where k is size of priority queue
    // push and pop O(log k)
    // top O(1)
    // space complexity
    // O(k)

    // how to identify problem
    // 1 ) top k frequent element
    // 2 ) top k smallest/largest
    // 3 ) clostest k
    // 4 ) or have to maintain max/min element on top 
    // sorting

    priority_queue<int> pq;
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);
    // maximum element on top of heap
    cout<<pq.top()<<endl; // 81
    pq.pop(); // 81 is removed 
    cout<<pq.top()<<endl; // 25 
    
}