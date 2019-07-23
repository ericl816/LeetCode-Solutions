/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode ans(0);
        ListNode *res = &ans;
        while (l1 && l2) {
            ListNode *&node = l1->val < l2->val ? l1 : l2;
            res = res->next = node;
            node = node->next;
        }
        res->next = l1 ? l1 : l2;
        return ans.next;
    }
};