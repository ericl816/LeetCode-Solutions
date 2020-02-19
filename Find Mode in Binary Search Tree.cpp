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
    void helper (TreeNode* node, int& prev, int& count, int& maxx, vector<int>& ans) {
        if (node == NULL) return;
        helper(node->left, prev, count, maxx, ans);
        if (node->val == prev) count++;
        else {
            prev = node->val;
            count = 1;
        }
        if (count >= maxx) {
            if (count > maxx) {
                maxx = count;
                ans.clear();
            }
            ans.push_back(node->val);
        }
        helper(node->right, prev, count, maxx, ans);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        int prev = 0, cnt = 0, maxx = -1;
        helper(root, prev, cnt, maxx, ans);
        return ans;
    }
};