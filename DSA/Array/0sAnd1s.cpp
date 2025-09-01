#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;

    while (i < j) {
        while (i < j && arr[i] == 0) i++;  // Ensure 'i' doesn't go out of bounds
        while (i < j && arr[j] == 1) j--;  // Ensure 'j' doesn't go out of bounds

        if (i < j) {
            swap(arr[i++], arr[j--]);  // Swap and move pointers
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0, 1};
    
    sortArray(arr);  // Call the corrected function
    
    for (auto ele : arr) {
        cout << ele << " ";
    }
    return 0;
}
