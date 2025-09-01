#include <iostream>
#include <vector>
using namespace std;
// In max heap visulization left and right node are smaller than root node 
// this code is similar like minHeap Implementation
class maxHeap {
public:
    int idx;
    vector<int> arr;

    maxHeap(int size) {
        arr = vector<int>(size + 1, 0);
        idx = 1;
    }

    int top() {
        if (idx == 1) return -1; // Handle empty heap case
        return arr[1];
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

    void push(int val) {
        if (idx >= arr.size()) return; // Prevent out-of-bounds insertion

        arr[idx] = val;
        int i = idx;
        idx++;

        while (i != 1) {
            int parent = i / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (idx == 1) return; // Heap is empty, nothing to pop

        idx--;
        arr[1] = arr[idx]; // Replace root with last element
        int i = 1;

        while (2 * i < idx) {
            int left = 2 * i, right = left + 1;
            int child = (right < idx && arr[right] > arr[left]) ? right : left;

            if (arr[i] >= arr[child]) break;

            swap(arr[i], arr[child]);
            i = child;
        }
    }
};

int main() {
    maxHeap pq(50);
    pq.push(100);
    pq.push(80);
    pq.push(90);
    pq.push(50);
    pq.push(40);
    pq.push(60);
    pq.push(70);
    
    pq.display();  // Output: 100 80 90 50 40 60 70
    cout << "Top : " << pq.top() << endl;  // Output: 100
    cout << "Size : " << pq.size() << endl;  // Output: 7

    pq.push(1000);
    pq.display();  // Output: 1000 100 90 80 40 60 70 50

    pq.pop();
    pq.display();  // Output: 100 80 90 50 40 60 70
}
