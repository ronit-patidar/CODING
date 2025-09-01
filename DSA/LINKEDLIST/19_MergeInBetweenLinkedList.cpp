// leetocde : 1669
// link : https://leetcode.com/problems/merge-in-between-linked-lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* curr2 = list1;
        ListNode* temp = list2;

        // Move `curr` to (a-1)-th node
        a--;
        while (a--) {
            curr = curr->next;
        }

        // Move `curr2` to (b+1)-th node
        b++;
        while (b--) {
            curr2 = curr2->next;
        }

        // Find the tail of list2
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Connect the tail of list2 to `curr2`
        if (temp) temp->next = curr2;

        // Connect `curr` to list2
        curr->next = list2;

        return list1;
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

    // Create list1
    vector<int> values1 = {0, 1, 2, 3, 4, 5};
    ListNode* list1 = createLinkedList(values1);

    // Create list2
    vector<int> values2 = {1000000, 1000001, 1000002};
    ListNode* list2 = createLinkedList(values2);

    int a = 3, b = 4;

    cout << "List1 before merge: ";
    printLinkedList(list1);

    cout << "List2: ";
    printLinkedList(list2);

    // Merge list2 into list1 between positions a and b
    ListNode* result = sol.mergeInBetween(list1, a, b, list2);

    cout << "List1 after merge: ";
    printLinkedList(result);

    return 0;
}
