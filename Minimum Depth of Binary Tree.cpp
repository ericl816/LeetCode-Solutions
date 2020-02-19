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
    int helper (TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int minn = INT_MAX;
        if (root->left) minn = min(minn, helper(root->left));
        if (root->right) minn = min(minn, helper(root->right));
        return minn + 1;
    }
    
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};