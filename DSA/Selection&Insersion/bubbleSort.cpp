#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;  // Reset for each pass
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swaps happened, the array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {5, 1, 3, 2, 4};
    bubbleSort(arr);
    for (auto ele : arr) {
        cout << ele << " ";
    }
    return 0;
}
