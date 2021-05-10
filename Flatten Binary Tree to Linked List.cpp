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
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        if (root->left != NULL) {
            flatten(root->left);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *res = root->right;
            while (res->right != NULL) res = res->right;
            res->right = temp;
        }
        flatten(root->right);
    }
};