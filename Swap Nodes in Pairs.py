# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return None
        if not head->next: return head
        res = ListNode(0)
        res->next = head
        curr = res
        
        while (curr->next and curr->next->next):
            first = curr->next
            second = curr->next->next
            curr->next = second
            first->next = second->next
            second->next = first
            curr = curr->next->next
        return res->next
        