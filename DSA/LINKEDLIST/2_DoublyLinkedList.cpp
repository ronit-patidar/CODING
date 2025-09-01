#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node(int val) {
        this->val = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            insertAtHead(val);
        } else if (index == size) {
            insertAtTail(val);
        } else {
            Node* temp = new Node(val);
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;
            size++;
        }
    }

    void deleteAtHead() {
        if (size == 0) return;
        Node* toDelete = head;
        if (size == 1) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete toDelete;
        size--;
    }

    void deleteAtTail() {
        if (size == 0) return;
        Node* toDelete = tail;
        if (size == 1) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete toDelete;
        size--;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            deleteAtHead();
        } else if (index == size - 1) {
            deleteAtTail();
        } else {
            Node* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            size--;
        }
    }

    int getAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayReverse() {
        Node* temp = tail;
        cout << "NULL";
        while (temp != NULL) {
            cout << "<-" << temp->val;
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList ll;
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.insertAtTail(9);
    ll.insertAtTail(10);
    ll.insertAtHead(5);
    ll.insertAtHead(4);
    ll.insertAtHead(3);
    ll.insertAtHead(2);
    ll.insertAtHead(1);

    ll.display();
    ll.displayReverse();

    cout << "\nDeleting head and tail...\n";
    ll.deleteAtHead();
    ll.deleteAtTail();
    ll.display();

    cout << "\nInserting 99 at index 3...\n";
    ll.insertAtIndex(3, 99);
    ll.display();

    cout << "\nDeleting index 3...\n";
    ll.deleteAtIndex(3);
    ll.display();

    cout << "\nValue at index 4: " << ll.getAtIndex(4) << endl;
}
