// leetcode : 160
// link : https://leetcode.com/problems/intersection-of-two-linked-lists
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Calculate the lengths of both linked lists
        while (tempA != nullptr) {
            lenA++;
            tempA = tempA->next;
        }
        while (tempB != nullptr) {
            lenB++;
            tempB = tempB->next;
        }

        // Reset pointers to the head of each list
        tempA = headA;
        tempB = headB;

        // Adjust the pointer of the longer list
        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++) {
                tempA = tempA->next;
            }
        } else {
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++) {
                tempB = tempB->next;
            }
        }

        // Traverse both lists together to find the intersection point
        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list with an intersection
ListNode* createIntersectedList(const int arrA[], int sizeA, const int arrB[], int sizeB, int intersectionIndex) {
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    ListNode* intersectNode = nullptr;

    // Create list A
    if (sizeA > 0) {
        headA = new ListNode(arrA[0]);
        ListNode* current = headA;
        for (int i = 1; i < sizeA; i++) {
            current->next = new ListNode(arrA[i]);
            current = current->next;
            if (i == intersectionIndex) {
                intersectNode = current;
            }
        }
    }

    // Create list B
    if (sizeB > 0) {
        headB = new ListNode(arrB[0]);
        ListNode* current = headB;
        for (int i = 1; i < sizeB; i++) {
            current->next = new ListNode(arrB[i]);
            current = current->next;
        }
        // Attach intersect node
        if (intersectNode != nullptr) {
            current->next = intersectNode;
        }
    }

    return headA;
}

// Helper function to free a linked list
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case: Create two intersecting linked lists
    int arrA[] = {4, 1};
    int arrB[] = {5, 6, 1};
    int common[] = {8, 4, 5};

    // Create the intersection part
    ListNode* intersectHead = nullptr;
    ListNode* current = nullptr;
    for (int val : common) {
        if (!intersectHead) {
            intersectHead = new ListNode(val);
            current = intersectHead;
        } else {
            current->next = new ListNode(val);
            current = current->next;
        }
    }

    // Create list A
    ListNode* headA = new ListNode(arrA[0]);
    current = headA;
    for (int i = 1; i < 2; i++) {
        current->next = new ListNode(arrA[i]);
        current = current->next;
    }
    current->next = intersectHead;

    // Create list B
    ListNode* headB = new ListNode(arrB[0]);
    current = headB;
    for (int i = 1; i < 3; i++) {
        current->next = new ListNode(arrB[i]);
        current = current->next;
    }
    current->next = intersectHead;

    // Print both lists
    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    // Find the intersection node
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    // Print the result
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    // Free memory
}
