// Given the root of a binary tree and an integer targetSum, return the number of paths where the 
// sum of the values along the path equals targetSum.
// The path does not need to start or end at the root or a leaf, but it must go downwards 
// (i.e., traveling only from parent nodes to child nodes).


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
void calc(struct TreeNode* root, int target, int* total_ptr, long int sum);
void walk(struct TreeNode* root, int target, int* total_ptr);
int pathSum(struct TreeNode* root, int targetSum);

// Function implementations
void calc(struct TreeNode* root, int target, int* total_ptr, long int sum) {
    if (!root) return;
    sum += root->val;
    if (sum == target) *total_ptr += 1;
    calc(root->left, target, total_ptr, sum);
    calc(root->right, target, total_ptr, sum);
}

void walk(struct TreeNode* root, int target, int* total_ptr) {
    if (!root) return;
    calc(root, target, total_ptr, 0);
    walk(root->left, target, total_ptr);
    walk(root->right, target, total_ptr);
    return;
}

int pathSum(struct TreeNode* root, int targetSum) {
    int total = 0;
    walk(root, targetSum, &total);
    return total;
}

// Helper function to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to free the binary tree
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Creating a binary tree
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(-3);
    root->left->left = createNode(3);
    root->left->right = createNode(2);
    root->right->right = createNode(11);
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(-2);
    root->left->right->right = createNode(1);

    int targetSum = 8;
    int result = pathSum(root, targetSum);
    printf("Number of paths with sum %d: %d\n", targetSum, result);

    // Freeing the binary tree
    freeTree(root);
    
    return 0;
}
