// Given a binary tree root, a node X in the tree is named good 
// if in the path from root to X there are no nodes with a value greater than X.
// Return the number of good nodes in the binary tree.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int count(TreeNode* root, int max)
{
    if (!root) return 0;
    int new_max = (root->val > max) ? root->val : max;
    int count_left = count(root->left, new_max);
    int count_right = count(root->right, new_max);
    return (root->val < max) ? count_right + count_left : count_right + count_left + 1;
}

int goodNodes(TreeNode* root) {
    if (!root) return 0;
    return count(root, root->val);
}

int main() {
    // Create an example tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    // Call the goodNodes function
    int result = goodNodes(root);
    cout << "Number of good nodes: " << result << endl;

    // Cleanup the dynamically allocated memory
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
