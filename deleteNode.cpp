// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
// Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val == key) {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = root->right->left;
        TreeNode* curr = root->left;
        root->right->left = root->left;
        while (curr->right) curr = curr->right;
        curr->right = temp;
        temp = root->right;
        delete root;
        return temp;
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    else root->right = deleteNode(root->right, key);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << "Inorder traversal of the original tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete a node
    int key = 3;
    root = deleteNode(root, key);

    std::cout << "Inorder traversal of the tree after deleting " << key << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Clean up the remaining tree nodes (you should ideally write a function for this)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
