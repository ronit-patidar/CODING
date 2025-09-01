// leetcode : 61
// link : https://leetcode.com/problems/rotate-list
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // Handle empty list or no rotation

        // Find the size of the list and the current tail
        int n = 1; // Start at 1 because we count the head
        ListNode* tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }

        // Compute effective rotations
        k = k % n;
        if (k == 0) return head; // No rotation needed

        // Find the new tail and new head
        int newTailIndex = n - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < newTailIndex; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        // Rotate the list
        newTail->next = nullptr; // Break the list
        tail->next = head;       // Connect the old tail to the old head

        return newHead;
    }
};

// Helper functions for testing
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    // Test case: List with multiple nodes
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Rotate the list
    Solution sol;
    head = sol.rotateRight(head, 2);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}
