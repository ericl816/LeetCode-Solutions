/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp = new ListNode(-1);
        ListNode *ans = temp;
        if (lists.empty()) {
            return ans->next;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > pq;
        // Order by val in ascending order
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) {
                pq.push(make_pair(lists[i]->val, lists[i]));
            }
        }
        while (!pq.empty()) {
            ListNode *node = pq.top().second;
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if (node->next) {
                pq.push(make_pair(node->next->val, node->next));
            }
        }
        return ans->next;
    }
};
