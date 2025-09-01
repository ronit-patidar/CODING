#include <iostream>
#include <vector>
using namespace std;

// Function to heapify for Max Heap (1-based indexing)
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i;      // Left child (1-based)
    int right = 2 * i + 1; // Right child (1-based)

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to heapify for Min Heap (1-based indexing)
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
        smallest = left;

    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build Max Heap from an array
void buildMaxHeap(vector<int>& arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to build Min Heap from an array
void buildMinHeap(vector<int>& arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to print heap
void printHeap(vector<int>& arr, int n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Example array with 1-based indexing (index 0 is unused)
    vector<int> arr = {-1, 3, 5, 9, 6, 8, 20, 10}; // Index 0 unused
    int n = arr.size() - 1; // Adjust size for 1-based indexing

    // Create Max Heap
    buildMaxHeap(arr, n);
    cout << "Max Heap: ";
    printHeap(arr, n);

    // Reset array to original values for Min Heap
    arr = {-1, 3, 5, 9, 6, 8, 20, 10 };

    // Create Min Heap
    buildMinHeap(arr, n);
    cout << "Min Heap: ";
    printHeap(arr, n);

    return 0;
}
