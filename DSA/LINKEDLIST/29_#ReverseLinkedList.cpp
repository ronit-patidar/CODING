// leetcode : 206
// link : https://leetcode.com/problems/reverse-linked-list
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
// recursive
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        // M2 recursive
        if(head==NULL || head->next==NULL) return head;// base case
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
};
// pointer method 
class Solution {
public:
    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *NEXT = head;
        while (curr) { // while curr != NULL
            NEXT = curr->next;  // Store the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev to the current node
            curr = NEXT;        // Move curr to the next node
        }
        return prev; // New head of the reversed list
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

    // Reverse the linked list
    ListNode* reversed = sol.reverseList(head);

    // Print the reversed linked list
    cout << "Reversed List: ";
    printList(reversed);

    return 0;
}
