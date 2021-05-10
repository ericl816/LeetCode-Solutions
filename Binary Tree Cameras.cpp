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
    void DFS (TreeNode *root, TreeNode *prev, set<TreeNode*> &s, int &ans) {
        if (root == NULL) return;
        DFS(root->left, root, s, ans);
        DFS(root->right, root, s, ans);
        if ((prev == NULL && !s.count(root)) || !s.count(root->left) || !s.count(root->right)) {
            ans++;
            s.insert(root);
            s.insert(prev);
            s.insert(root->left);
            s.insert(root->right);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        set<TreeNode*> s;
        s.insert(NULL);
        DFS(root, NULL, s, ans);
        return ans;
    }
};