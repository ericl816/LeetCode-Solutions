/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    vector<int> ans;
    
    // Iterative
    vector<int> preorder(Node* root) {
        if (root == NULL) return ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node *curr = st.top();
            st.pop();
            for (int i=curr->children.size() - 1; i>=0; i--) {
                if (curr->children[i] != NULL) st.push(curr->children[i]);
            }
            ans.push_back(curr->val);
        }
        return ans;
    }

    // Recursive
    vector<int> preorder1(Node* root) {
        if (root == NULL) return ans;
        ans.push_back(root->val);
        for (auto i : root->children) preorder(i);
        return ans;
    }
};