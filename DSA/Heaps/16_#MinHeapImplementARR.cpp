#include<iostream>
#include<vector>
using namespace std;
// heap visulize as tree(left and right nodes are greater than node ) and implement as array
class MinHeap {
public:
    int idx; // initialization not allowed here always intialize in constructor
    vector<int> arr;
    
    MinHeap(int size) {
        arr=vector<int>(size+1,0);
        // size+1 because of one based indexing 
        idx = 1;  // Index starts at 1 for 1-based heap indexing
        // why not 0 ? not maintain parent and child access easy
    }
    
    int top() {
        return arr[1];  // Return the root element (minimum)
    }
    
    int size() {
        return idx - 1;
    }
    
    void display() {
        for (int i = 1; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void push(int x) {
        if(idx>arr.size()){
            cout<<"Heap Overflow";
            return ;
        }
        arr[idx] = x;   // Insert the new element at the end of the heap
        int i = idx;    // Store the current index of the newly inserted element
        idx++;          // Increment the index for the next insertion
    
        // Restore the heap property (min-heap) by swapping the element with its parent if necessary
        while (i != 1) {  // Continue until we reach the root node
            int parent = i / 2;  // Calculate the index of the parent node
     
            if (arr[i] < arr[parent]) {  // If the child is smaller than the parent, swap them
                swap(arr[i], arr[parent]);
            } else {
                break;  // If the heap property is maintained, stop swapping
            }
            
            i = parent;  // Move up to the parent's position and repeat the process
        }
    }
        
    void pop() {
        if (idx == 1) return; // Heap is empty, nothing to pop
    
        idx--;  // Reduce heap size
        swap(arr[1], arr[idx]);  // Swap root with last element
        int i = 1;
    
        while (2 * i < idx) {  // Ensure at least one child exists
            int left = 2 * i, right = left + 1;
            int child = (right < idx && arr[right] < arr[left]) ? right : left;  // Find smaller child
    
            if (arr[i] <= arr[child]) break;  // Correct position found
    
            swap(arr[i], arr[child]);  // Swap with smaller child
            i = child;
        }
    }
};

int main() {
    MinHeap pq(50);
    pq.push(10);
    pq.push(20);
    cout << pq.top() << " " << pq.size() << endl;  // Output: 10 2
    pq.push(11);
    pq.push(2);
    cout << pq.top() << " " << pq.size() << endl;  // Output: 2 4
    pq.display();  // Output: 2 10 11 20
    pq.pop();
    cout << pq.top() << " " << pq.size() << endl;  // Output: 10 3
    pq.display();  // Output: 10 20 11
}
