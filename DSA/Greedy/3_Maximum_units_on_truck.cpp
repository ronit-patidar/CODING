//Maximum Units on a Truck
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Custom comparator function to sort based on the second element (number of units per box)
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort the boxTypes using the comparator
        sort(boxTypes.begin(), boxTypes.end(), cmp); // Sort by units per box in descending order
        
        int profit = 0;
        for(int i = 0; i < boxTypes.size(); i++) {
            if(boxTypes[i][0] <= truckSize) {
                profit += boxTypes[i][0] * boxTypes[i][1]; // All boxes fit
                truckSize -= boxTypes[i][0]; // Reduce truck capacity
            } else {
                profit += truckSize * boxTypes[i][1]; // Take as many boxes as truckSize allows
                truckSize = 0;
            }
            if(truckSize == 0) break; // Stop if the truck is full
        }
        return profit;
    }
};

int main() {
    // Example input
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    
    // Create an instance of Solution and call maximumUnits
    Solution sol;
    int result = sol.maximumUnits(boxTypes, truckSize);
    
    // Output the result
    cout << "Maximum units that can be loaded on the truck: " << result << endl;
    
    return 0;
}
