/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height (TreeNode *root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        return max(height(root->left) + height(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};