// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and 
// return the subtree rooted with that node. If such a node does not exist, return null.


#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val==val) return root;
    if(root->val>val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}

// Helper function to insert nodes in a BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

// Helper function to print the tree (in-order traversal)
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;

    int val = 6;
    TreeNode* result = searchBST(root, val);

    if (result) {
        cout << "Node with value " << val << " found in the BST." << endl;
    } else {
        cout << "Node with value " << val << " not found in the BST." << endl;
    }

    return 0;
}
