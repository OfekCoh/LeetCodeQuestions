// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of the tree
int height(TreeNode* root) {
    if (!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return std::max(left, right) + 1;
}

// Function to calculate the sum of values at each level
void calc(TreeNode* root, std::vector<int>& vec, int h) {
    if (!root) return;
    vec[h] += root->val;
    calc(root->left, vec, h + 1);
    calc(root->right, vec, h + 1);
}

// Function to find the level with the maximum sum
int maxLevelSum(TreeNode* root) {
    if (!root) return 0;
    int h = height(root);
    std::vector<int> vec(h, 0);
    calc(root, vec, 0);
    int maxSum = vec[0];
    int level = 0;
    for (int i = 1; i < h; ++i) {
        if (vec[i] > maxSum) {
            maxSum = vec[i];
            level = i;
        }
    }
    return level + 1;
}

// Helper function to insert nodes in the tree for testing
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    // Find the level with the maximum sum
    int maxLevel = maxLevelSum(root);

    std::cout << "Level with maximum sum: " << maxLevel << std::endl;

    // Clean up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
