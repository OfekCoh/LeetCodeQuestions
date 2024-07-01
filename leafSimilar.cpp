// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void addLeaves(TreeNode* root, vector<int>& vec)
{
    if(!root) return;
    if(!root->left && !root->right) 
    {
        vec.push_back(root->val);
        return;
    }
    addLeaves(root->left, vec);
    addLeaves(root->right, vec);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> first, second;
    addLeaves(root1, first);
    addLeaves(root2, second);
    if(first.size() != second.size()) return false;
    for(int i = 0; i < first.size(); i++)
    {
        if(first[i] != second[i]) return false;
    }
    return true;
}

int main() {
    // Create two example trees
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    // Check if the trees are leaf-similar
    bool result = leafSimilar(root1, root2);
    cout << (result ? "The trees are leaf-similar." : "The trees are not leaf-similar.") << endl;

    // Cleanup the dynamically allocated memory
    delete root1->left->right->left;
    delete root1->left->right->right;
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->right;
    delete root1;

    delete root2->right->right->left;
    delete root2->right->right->right;
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}
