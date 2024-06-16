#include <iostream>
using namespace std;

struct TreeNode {
    int val;

    int maxL;
    int maxR;

    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr), maxL(0), maxR(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void calc(TreeNode* root, int& max)
{
    if(!root) return;
    calc(root->left, max);
    calc(root->right, max);

    if(!root->left) root->maxL=0;
    else{
        root->maxL= root->left->maxR+1;
        if(root->maxL > max) max=root->maxL;
    }

    if(!root->right) root->maxR=0;
    else{
        root->maxR= root->right->maxL+1;
        if(root->maxR > max) max=root->maxR;
    }
}

int longestZigZag(TreeNode* root) {
    int max=0;
    if(root) calc(root, max);
    return max;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->right->right = new TreeNode(1);

    cout << longestZigZag(root);

    return 0;
}