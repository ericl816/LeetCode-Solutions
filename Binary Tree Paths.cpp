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
    
    void DFS (TreeNode* node, string s, vector<string> &ans) {
        if (!node) return;
        if (node->left == NULL && node->right == NULL) ans.push_back(s + to_string(node->val));
        if (node->left) DFS(node->left, s + to_string(node->val) + "->", ans);
        if (node->right) DFS(node->right, s + to_string(node->val) + "->", ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        DFS(root, "", ans);
        return ans;
    }
};