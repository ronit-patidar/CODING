// https://www.geeksforgeeks.org/count-bst-subtrees-that-lie-in-given-range/

// C++ program to count BST subtrees
// that lie in given range
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to count
// subtrees that lie in a range
bool subtreeCntRecur(Node* root, int low, int high, int &ans) {
    if (root == nullptr) return true;
    
    // Check for left and right subtree.
    bool left = subtreeCntRecur(root->left, low, high, ans);
    bool right = subtreeCntRecur(root->right, low, high, ans);
    
    // If current subtree lies within range, then increment
    // ans count and return true.
    if (root->data>=low && root->data<=high && left && right) {
        ans++;
        return true;
    }
    
    // Else return false as this subtree 
    // is out of range.
    return false;
}

// Function to count subtress that 
// lie in a given range
int subtreeCnt(Node* root, int low, int high) {
    int ans = 0;
    subtreeCntRecur(root, low, high, ans);
    
    return ans;
}

int main() {
    
    // Binary tree 
    //         10
    //       /    \
    //     5       50
    //   /       /  \
    //  1       40   100
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    int low = 1, high = 45;
    
    cout << subtreeCnt(root, low, high) << endl;
    
    return 0;
}