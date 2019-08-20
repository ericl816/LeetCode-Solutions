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
    
    int sum[10010];
    int maxdepth, ans;
    
    void DFS (TreeNode *node, int depth) {
        if (node == NULL) return;
        maxdepth = max(maxdepth, depth);
        sum[depth] += node->val;
        DFS(node->left, depth + 1);
        DFS(node->right, depth + 1);
    }
    
    int maxLevelSum(TreeNode* root) {
        DFS(root, 0);
        for (int i=0; i<=maxdepth; i++) {
            if (sum[ans] < sum[i]) ans = i;
        }
        return ans + 1;
    }
};