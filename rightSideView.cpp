// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void getVec(TreeNode* root, vector<int>& vec, int& maxDepth, int currentDepth) {
    if (!root) return;

    if (currentDepth > maxDepth) {
        vec.push_back(root->val);
        maxDepth = currentDepth;
    }

    getVec(root->right, vec, maxDepth, currentDepth + 1);
    getVec(root->left, vec, maxDepth, currentDepth + 1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> vec;
    int maxDepth = -1; // Initialize maxDepth to -1 to start counting from 0
    getVec(root, vec, maxDepth, 0);
    return vec;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Get the right side view of the binary tree.
    vector<int> result = rightSideView(root);

    // Print the result.
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup memory (not necessary for the scope of this example, but good practice)
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
