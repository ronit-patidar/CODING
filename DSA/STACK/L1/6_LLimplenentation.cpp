#include<iostream>
using namespace std;

// This code demonstrates the implementation of a stack using a linked list.
// Unlike an array or vector, a linked list allows for a stack with unlimited size.
// Linked List is push at tail by default.

class ListNode { // Define a class for the nodes of the linked list
public:
    int val; // Value of the node
    ListNode* next; // Pointer to the next node in the list

    ListNode(int val) { // Constructor to initialize a node
        this->val = val; // Set the value of the node
        this->next = NULL; // Initialize the next pointer to NULL
    }
};

class stack { // Define a class for the stack
public:
    ListNode* head; // Pointer to the head (top) of the stack
    int size; // Variable to track the size of the stack

    stack() { // Constructor to initialize the stack
        head = NULL; // Initialize the head pointer to NULL
        size = 0; // Initialize the size to 0
    }

    void push(int val) { // Function to push a value onto the stack
        size++; // Increment the size of the stack
        ListNode* temp = new ListNode(val); // Create a new node with the given value
        temp->next = head; // Set the new node's next pointer to the current head
        head = temp; // Update the head to the new node
    }

    int pop() { // Function to pop a value from the stack
        if (head == NULL) { // Check if the stack is empty
            cout << "Stack is empty" << endl;
            return -1; // Return a default value (or handle empty case appropriately)
        }
        int poppedValue = head->val; // Store the value of the popped element
        head = head->next; // Update the head to the next node
        size--; // Decrement the size of the stack
        return poppedValue; // Return the popped element
    }

    int top() { // Function to get the top value of the stack
        if (head == NULL) { // Check if the stack is empty
            cout << "Stack is empty" << endl;
            return -1; // Return a default value (or handle empty case appropriately)
        }
        return head->val; // Return the value of the top element
    }

    void print(ListNode* temp) { // Helper function to print the stack recursively
        if (temp == NULL) return; // Base case: if the node is NULL, return
        print(temp->next); // Recursive call to print the next node
        cout << temp->val << " "; // Print the value of the current node
    }

    void display() { // Function to display the stack
        ListNode* temp = head; // Start from the head of the stack
        print(temp); // Use the print helper function
        cout << endl;
    }

    void displayrev() { // Function to display the stack in reverse order
        ListNode* temp = head; // Start from the head of the stack
        while (temp != NULL) { // Traverse the stack
            cout << temp->val << " "; // Print the value of each node
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    stack st; // Create a stack object

    // Push values onto the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    // ll will be 60 50 40 30 20 10

    // Display the stack using recursive print
    st.display(); // Output: 10 20 30 40 50 60

    // Display the stack in reverse order
    st.displayrev(); // Output: 60 50 40 30 20 10

    return 0;
}
