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
    
    int ans = INT_MAX;
    int prev = -1;
    
    void DFS(TreeNode* root) {
        if (!root) return;
        DFS(root->left);
        if (prev != -1) ans = min(ans, root->val - prev);
        prev = root->val;
        DFS(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        DFS(root);  
        return ans;
    }
};