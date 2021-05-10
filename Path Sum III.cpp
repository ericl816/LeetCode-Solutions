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
    void helper (TreeNode* root, int &res, int sum, int curr, unordered_map<int, int>& mp) {
        if(root == NULL) return;
        curr += root->val;
        if (mp.count(curr - sum)) res += mp[curr - sum];  
        mp[curr]++;
        helper(root->left, res, sum, curr, mp);   
        helper(root->right, res, sum, curr, mp);
        mp[curr]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        helper(root, res, sum, 0, mp);
        return res;
    }
};