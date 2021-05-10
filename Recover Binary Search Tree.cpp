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
    void inorder (TreeNode *root, vector<int> &v) {
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* sort_nodes (TreeNode *root, vector<int> &v, int &idx) {
        if (root == NULL) return root;
        root->left = sort_nodes(root->left, v, idx);
        root->val = v[idx++];
        root->right = sort_nodes(root->right, v, idx);
        return root;
    }
    
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int idx = 0;
        root = sort_nodes(root, v, idx);
    }
};