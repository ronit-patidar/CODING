// leetcode no : 108
// link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode{ // This is tree node at LEETCODE
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
       this->val=val;
       this->left=NULL;
       this->right=NULL;
    }
};

// Solution class with the helper and sortedArrayToBST functions
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return NULL; // Base case
        int mid = lo + (hi - lo) / 2; // Find the middle element
        TreeNode* root = new TreeNode(nums[mid]); // Create root node
        root->left = helper(nums, lo, mid - 1); // Recursively build left subtree
        root->right = helper(nums, mid + 1, hi); // Recursively build right subtree
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Level-order traversal function to display the tree
void levelOrderQueue(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {-10, -3, 0, 5, 9}; // Input sorted array
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(arr); // Convert to BST
    cout << "Level-order traversal of the constructed BST:" << endl;
    levelOrderQueue(root); // Print level-order traversal
    return 0;
}
