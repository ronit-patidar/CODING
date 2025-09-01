#include<iostream>
#include<queue>
using namespace std;
int main(){
        // MIN HEAP

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
        priority_queue< int, vector<int> , greater<int> > pq;
        pq.push(10);
        pq.push(25);
        pq.push(-6);
        pq.push(81);
        // minimum element on top of heap
        cout<<pq.top()<<endl; // -6
        pq.pop(); // -6 is removed 
        cout<<pq.top()<<endl; // 10 
    
}