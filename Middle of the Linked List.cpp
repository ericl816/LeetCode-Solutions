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
    ListNode* middleNode(ListNode* head) {
        ListNode *A = head;
        ListNode *B = head;
        while (A && A->next) {
            A = A->next->next;
            B = B->next;
        }
        return B;
    }
};