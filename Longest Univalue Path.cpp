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
    
    int DFS (TreeNode *node, int &ans) {
        int l = node->left ? DFS(node->left, ans) : 0;
        int r = node->right ? DFS(node->right, ans) : 0;
        int vall = node->left && node->left->val == node->val ? l + 1 : 0;
        int valr = node->right && node->right->val == node->val ? r + 1 : 0;
        ans = max(ans, vall + valr);
        return max(vall, valr);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        if (root) DFS(root, ans);
        return ans;
    }
};