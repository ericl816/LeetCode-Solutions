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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL, *temp = NULL, *prev = NULL;
        int sum = 0, carry = 0;
        while (l1 != NULL || l2 != NULL) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            temp = new ListNode(sum);
            if (ans == NULL) ans = temp;
            else prev->next = temp;
            prev = temp;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) temp->next = new ListNode(carry);
        return ans;
    }
};