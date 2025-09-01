// leetcode : 21
// link : https://leetcode.com/problems/merge-two-sorted-lists
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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // Method 2: In-place merging, Space Complexity O(1)
        ListNode* c = new ListNode(100); // Dummy node to simplify merging
        ListNode* t = c;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }

        // Attach the remaining nodes
        if (a == nullptr) {
            t->next = b;
        } else {
            t->next = a;
        }

        return c->next; // Return merged list, skipping the dummy node
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for (int x : arr) {
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    return dummy->next;
}

// Main function for testing
int main() {
    // Create test linked lists
    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};

    ListNode* a = createList(list1);
    ListNode* b = createList(list2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(a, b);

    // Print merged list
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
