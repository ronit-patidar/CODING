// leetcode : 203
// link : https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        if ((head == NULL) || (head->val == val && !head->next)) return NULL;
        while (temp && temp->val == val) {
            if (temp->next == NULL) return NULL;
            temp = temp->next;
        }
        head = temp;
        while (temp != NULL) {
            if (temp->next && temp->next->val == val) {
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

ListNode* createList(vector<int> values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    // Create a linked list [1, 2, 6, 3, 4, 5, 6]
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Remove elements with value 6
    Solution sol;
    head = sol.removeElements(head, 6);

    cout << "Updated list: ";
    printList(head);

    return 0;
}
