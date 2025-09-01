// leetcode : 86
// link : https://leetcode.com/problems/partition-list
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(0); // Dummy node for smaller values
        ListNode* hi = new ListNode(0); // Dummy node for larger or equal values
        ListNode* tl = lo; // Pointer for smaller values list
        ListNode* th = hi; // Pointer for larger or equal values list
        ListNode* t = head;

        // Traverse the original list and partition it
        while (t != nullptr) {
            if (t->val < x) {
                tl->next = t;
                t = t->next;
                tl = tl->next;
            } else { // t->val >= x
                th->next = t;
                t = t->next;
                th = th->next;
            }
        }

        // Connect the smaller values list to the larger values list
        tl->next = hi->next;
        th->next = nullptr;

        return lo->next; // Return the head of the new list
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for (int x : arr) {
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    vector<int> nums = {1, 4, 3, 2, 5, 2};
    int x = 3;

    // Create the linked list
    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;

    // Partition the list
    ListNode* partitioned = sol.partition(head, x);

    // Print the result
    cout << "Partitioned List: ";
    printList(partitioned);

    return 0;
}
