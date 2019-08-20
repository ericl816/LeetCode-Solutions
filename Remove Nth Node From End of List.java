/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    	ListNode node = head;
    	ListNode resnode = head;
    	while (n-->0) node = node.next;
    	if (node == null) return head.next;
    	while (node.next != null) {
    		node = node.next;
            resnode = resnode.next;
    	}
        resnode.next = resnode.next.next;
        return node;
    }
}