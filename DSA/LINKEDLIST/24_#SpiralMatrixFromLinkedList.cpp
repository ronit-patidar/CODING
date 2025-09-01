// leetcode : 2326
// link : https://leetcode.com/problems/spiral-matrix-iv 
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> arr(m, vector<int>(n, -1));

        int minr = 0; // Minimum row
        int minc = 0; // Minimum column
        int maxr = m - 1; // Maximum row
        int maxc = n - 1; // Maximum column

        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc) {
            // Traverse right along the top row
            for (int j = minc; j <= maxc && temp; j++) {
                arr[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++; // Move to the next row

            // Traverse down along the right column
            for (int i = minr; i <= maxr && temp; i++) {
                arr[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--; // Move to the previous column

            // Traverse left along the bottom row
            for (int j = maxc; j >= minc && temp; j--) {
                arr[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--; // Move to the previous row

            // Traverse up along the left column
            for (int i = maxr; i >= minr && temp; i--) {
                arr[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++; // Move to the next column
        }

        return arr;
    }
};

int main() {
    // Create a linked list for testing: [1, 2, 3, 4, 5, 6, 7, 8]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    Solution solution;
    vector<vector<int>> result = solution.spiralMatrix(3, 3, head);

    // Print the resulting spiral matrix
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
