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
    vector<int> postorder(Node* root) {
        if (root == NULL) return ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node *curr = st.top();
            st.pop();
            for (auto i : curr->children) st.push(i);
            ans.push_back(curr->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Recursive
    vector<int> postorder(Node* root) {
        if (root == NULL) return ans;
        for (auto i : root->children) postorder(i);
        ans.push_back(root->val);
        return ans;
    }
};