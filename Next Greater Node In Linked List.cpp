/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> st, res;
        for (ListNode *node = head; node; node = node->next) res.push_back(node->val);
        vector<int>ans(res.size());
        for (size_t i=0; i<res.size(); i++) {
            while (!st.empty() && res[st.back()] < res[i]) {
                ans[st.back()] = res[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};