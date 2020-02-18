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
    bool isValidBSTHelper (TreeNode *root, long long minn, long long maxx) {
        if (root == NULL) return 1;
        int val = root->val;
        if (minn < val && val < maxx) {
            return isValidBSTHelper(root->left, minn, val) && isValidBSTHelper(root->right, val, maxx);
        }
        return 0;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};