// leetcode : 83
// link : https://leetcode.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->next && (temp->val == temp->next->val)) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Helper functions for testing
void printList(ListNode* head) {
    while (head != nullptr) {
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
    // Create a sorted linked list with duplicates [1, 1, 2, 3, 3]
    vector<int> values = {1, 1, 2, 3, 3};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "Updated list: ";
    printList(head);

    return 0;
}
