// leetocde : 1721
// link : https://leetcode.com/problems/swapping-nodes-in-a-linked-list
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        k--;
        
        // Move to the k-th node (k is 1-indexed, so decrement by 1)
        while (k--) {
            temp = temp->next;
        }

        ListNode* temp2 = head;
        ListNode* p2 = temp->next;  // k-th node's next node
        ListNode* p1 = head;

        // Traverse the list until p2 reaches the end
        while (p2 != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }

        // p1 will be at the (len-k+1)-th node, the node to swap with the k-th node
        swap(temp->val, p1->val);
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

    // Create a linked list
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    int k = 2;  // Swap the 2nd node from the start with the 2nd node from the end

    cout << "Original list: ";
    printLinkedList(head);

    // Swap nodes
    head = sol.swapNodes(head, k);

    cout << "List after swapping nodes: ";
    printLinkedList(head);

    return 0;
}
