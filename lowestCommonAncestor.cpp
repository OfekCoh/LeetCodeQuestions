// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: 
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as 
// descendants 
// (where we allow a node to be a descendant of itself).”


#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the lowest common ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (!left && !right) return nullptr;
    if (left && right) return root;
    return !left ? right : left;
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
    TreeNode* root = new TreeNode(6);
    insertNode(root, 2);
    insertNode(root, 8);
    insertNode(root, 0);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 3);
    insertNode(root, 5);

    // Find nodes to be used as p and q
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->left->right; // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found" << std::endl;
    }

    // Clean up allocated memory
    delete root;

    return 0;
}
