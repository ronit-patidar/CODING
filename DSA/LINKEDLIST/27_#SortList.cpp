// leetcode : 148
// link : https://leetcode.com/problems/sort-list
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
    // Merge two sorted linked lists
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100); // Dummy node
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

        // Attach remaining nodes
        if (a == nullptr) t->next = b;
        else t->next = a;

        return c->next; // Skip the dummy node
    }

    // Sort a linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case of recursion
        if (head == nullptr || head->next == nullptr) return head;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = nullptr;

        // Recursively sort each half
        a = sortList(a);
        b = sortList(b);

        // Merge the two sorted halves
        return merge(a, b);
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
    vector<int> nums = {4, 2, 1, 3};

    // Create the linked list
    ListNode* head = createList(nums);

    Solution sol;

    // Sort the linked list
    ListNode* sorted = sol.sortList(head);

    // Print the sorted linked list
    cout << "Sorted List: ";
    printList(sorted);

    return 0;
}
