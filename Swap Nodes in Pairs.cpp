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
	// Recursive
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* node = head->next;
        head->next = swapPairs(node->next);
        node->next = head;
        return node;
    }
};