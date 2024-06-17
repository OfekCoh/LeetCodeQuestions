// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
// defined between two nodes p and q as the lowest node in
//  T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the lowest common ancestor.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (!left && !right) return nullptr; 
    if (left && right) return root;  
    return !left ? right : left;
}

// Helper function to insert nodes into the binary tree for testing.
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Creating a binary tree.
    int arr[] = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}; // -1 represents null
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    // Assign p and q nodes
    TreeNode* p = root->left;      // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    TreeNode* ancestor = lowestCommonAncestor(root, p, q);
    if (ancestor) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << ancestor->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    return 0;
}
