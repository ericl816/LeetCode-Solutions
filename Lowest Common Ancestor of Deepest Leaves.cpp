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
    
    int getLevel (TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int left = getLevel(root->left), right = getLevel(root->right);
        return left > right ? left + 1 : right + 1;
    }
    
    TreeNode* Solve (TreeNode *root) {
        // cout << root->val << " ";
        if (root == NULL) return root;
        if (root->left == NULL && root->right == NULL) return root;
        int left = getLevel(root->left), right = getLevel(root->right);
        if (left == right) return root;
        else {
            return left > right ? Solve(root->left) : Solve(root->right);
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return root;
        if (root->left == NULL && root->right == NULL) return root;
        else return Solve(root);
    }
};