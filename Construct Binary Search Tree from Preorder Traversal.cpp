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
    int idx;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parent = INT_MAX) {
        if (idx == preorder.size() || preorder[idx] > parent) return NULL;
        int val = preorder[idx++];
        TreeNode *temp = new TreeNode(val);
        temp->left = bstFromPreorder(preorder, val);
        temp->right = bstFromPreorder(preorder, parent);
        return temp;
    }
};