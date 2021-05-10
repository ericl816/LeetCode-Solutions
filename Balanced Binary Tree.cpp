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
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return 1;
        int lheight = height(root->left), rheight = height(root->right);
        return abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};