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
    
    set<int> flag; // Unordered is sometimes slower due to collisions --> not ideal
    
    TreeNode* DFS (TreeNode *node, bool add, vector<TreeNode*> &ans) {
        if (!node) return NULL;
        if (flag.count(node->val)) { // Found a node to delete --> must add its left and right children nodes
            DFS(node->left, 1, ans);
            DFS(node->right, 1, ans);
            return NULL;
        }
        else { // Node isn't in set of nodes to delete so don't add --> its chlidren nodes are either in shared subtree already or need to be removed
            if (add) ans.push_back(node);
            node->left = DFS(node->left, 0, ans);
            node->right = DFS(node->right, 0, ans);
            return node;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        for (auto i : to_delete) flag.insert(i);
        DFS(root, 1, ans);
        return ans;
    }
};