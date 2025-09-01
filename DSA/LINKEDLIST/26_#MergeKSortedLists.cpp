// leetcode : 23
// link : https://leetcode.com/problems/merge-k-sorted-lists
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

        return c->next; // Return merged list, skipping the dummy node
    }

    // Merge K sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.empty()) return nullptr;

        while (arr.size() > 1) {
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = merge(a, b);
            arr.push_back(c);
        }

        return arr[0];
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
    // Create test linked lists
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};

    vector<ListNode*> lists;
    lists.push_back(createList(list1));
    lists.push_back(createList(list2));
    lists.push_back(createList(list3));

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    // Print the merged list
    cout << "Merged K Lists: ";
    printList(merged);

    return 0;
}
