// leetcode : 143
// link : https://leetcode.com/problems/reorder-list
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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; // Base case
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newhead = reverse(slow->next);
        slow->next = nullptr; // Split the list into two halves

        // Merge the two halves
        while (newhead) {
            ListNode* temp1 = head->next;
            ListNode* temp2 = newhead->next;
            head->next = newhead;
            newhead->next = temp1;
            head = temp1;
            newhead = temp2;
        }
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
    vector<int> nums = {1, 2, 3, 4, 5};

    // Create the linked list
    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;

    // Reorder the list
    sol.reorderList(head);

    // Print the reordered list
    cout << "Reordered List: ";
    printList(head);

    return 0;
}
