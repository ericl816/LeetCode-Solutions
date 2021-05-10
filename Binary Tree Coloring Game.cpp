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
    
    TreeNode* Find (TreeNode *node, int x) {
        if (node == NULL) return NULL;
        if (node->val == x) return node;
        TreeNode *l = Find(node->left, x), *r = Find(node->right, x);
        return l == NULL ? r : l;
    }
    
    int Size (TreeNode *node) {
        if (node == NULL) return 0;
        return 1 + Size(node->left) + Size(node->right);
    }
        
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *node = Find(root, x);
        int l = Size(node->left), r = Size(node->right), res = n - l - r - 1;
        int maxx = max(l, max(r, res));
        return maxx > n / 2;
    }
};