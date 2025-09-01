// leetcode : 234
// link : https://leetcode.com/problems/palindrome-linked-list
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
    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *NEXT = head;
        while (curr) {
            NEXT = curr->next;    // Store the next node
            curr->next = prev;    // Reverse the current node's pointer
            prev = curr;          // Move prev to the current node
            curr = NEXT;          // Move curr to the next node
        }
        return prev; // New head of the reversed list
    }

    // Check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // Single node or empty list is a palindrome

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newhead = reverseList(slow->next);

        // Compare the two halves
        ListNode* a = head;
        ListNode* b = newhead;
        while (b) { // Only need to compare up to the length of the second half
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
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
    vector<int> nums = {1, 2, 2, 1};

    // Create the linked list
    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;

    // Check if the linked list is a palindrome
    bool result = sol.isPalindrome(head);

    // Print the result
    if (result) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
