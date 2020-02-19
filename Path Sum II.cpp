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
    void helper (TreeNode *root, vector<int> path, vector<vector<int> > &ans, int sum) {
        if (root == NULL) return;
        sum -= root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && !sum) {
            ans.push_back(path);
        }
        helper(root->left, path, ans, sum);
        helper(root->right, path, ans, sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<int> path;
        helper(root, path, ans, sum);
        return ans;
    }
};