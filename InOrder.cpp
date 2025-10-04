#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val=0, TreeNode* left=nullptr, TreeNode* right=nullptr): val(val), left(left), right(right) {}

};

// just a normal implementation of dfs.
void InORder(TreeNode* head)
{
    if(!head) return;
    InORder(head->left);
    cout << head->val << " ";
    InORder(head->right);
}

void freeMem(TreeNode* root)
{
    if(!root) return;
    freeMem(root->left);
    freeMem(root->right);
    free(root);
}

int main()
{
    // Creating a simple tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    InORder(root);
    freeMem(root);  // free memory
}
