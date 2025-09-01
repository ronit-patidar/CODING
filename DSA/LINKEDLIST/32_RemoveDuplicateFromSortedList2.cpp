// leetcode : 82
// link : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                temp->next = head->next;
            } else {
                temp = temp->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case
    vector<int> vals = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = createLinkedList(vals);
    
    Solution sol;
    ListNode* result = sol.deleteDuplicates(head);
    
    printLinkedList(result);
    
    return 0;
}
