// leetcode : 2095
// link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* slow=head;
         ListNode* fast=head;
         while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
         }
        //  ListNode* curr=head;
        //  if(curr==NULL || curr->next==NULL) return NULL;
        //  while(curr->next!=slow){
        //     curr=curr->next;
        //  }
        //  curr->next=curr->next->next;
        //  return head;
         ListNode* curr=head;
         ListNode* prev=NULL;
         while(curr!=slow){
             prev=curr;
             curr=curr->next;
         }
        prev->next=curr->next;
        return head;
    }
};
// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
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

// Main function for testing
int main() {
    Solution sol;

    // Example test case
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    // Delete the middle node
    head = sol.deleteMiddle(head);

    cout << "List after deleting middle: ";
    printLinkedList(head);

    return 0;
}
