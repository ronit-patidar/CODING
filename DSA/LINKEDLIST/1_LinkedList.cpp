#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
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
            head = temp;
        }
        size++;
    }

    void insertAtidx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid idx" << endl;
            return;
        }
        if (idx == 0) insertAtHead(val);
        else if (idx == size) insertAtTail(val);
        else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i <= idx - 1; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int getAtidx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid idx" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void deleteAtHead() {
        if (size == 0) {
            cout << "LL is empty" << endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        if (size == 0) tail = NULL;
    }

    void deleteAtTail() {
        if (size == 0) {
            cout << "LL is empty" << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            temp->next = NULL;
            tail = temp;
        }
        size--;
    }

    void deleteAtIdx(int idx) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        if (idx < 0 || idx >= size) {
            cout << "Invalid idx" << endl;
            return;
        }
        if (idx == 0) {
            deleteAtHead();
        } else if (idx == size - 1) {
            deleteAtTail();
        } else {
            Node* temp = head;
            for (int i = 1; i <= idx - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            size--;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insertAtTail(10);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtTail(20);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtTail(30);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtTail(40);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtHead(50);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtHead(24);
    ll.display();
    cout << "size " << ll.size << endl;

    ll.insertAtidx(4, 80);
    ll.display();
    cout << "size " << ll.size << endl;

    cout << ll.getAtidx(2) << endl;

    ll.deleteAtHead();
    ll.display();

    ll.deleteAtTail();
    ll.display();

    ll.deleteAtIdx(3);
    ll.display();
}
