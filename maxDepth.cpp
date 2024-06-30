// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the maximum depth of a binary tree.
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left, right;
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return (left > right) ? left + 1 : right + 1;
}

int main() {
    // Create a simple binary tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Maximum depth of the binary tree is: " << maxDepth(root) << std::endl;

    // Clean up memory (delete the nodes)
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
