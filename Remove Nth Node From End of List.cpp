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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head;
        ListNode *resnode = head;
        while (n--) node = node->next;

        // n is equal to length of linked list --> remove head
        if (node == NULL) return head->next;

        while (node->next != NULL) {
        	node = node->next;
        	resnode = resnode->next;
        }
        // Skip (remove) nth node from end of list
        resnode->next = resnode->next->next;
        return head;
    }
};