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
    bool pruneNoOnes (TreeNode *root) {
        if (root == NULL) return 0;
        if (pruneNoOnes(root->left)) root->left = NULL;
        if (pruneNoOnes(root->right)) root->right = NULL;
        return root->left == NULL && root->right == NULL && root->val == 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        pruneNoOnes(root);
        return root;
    }
};