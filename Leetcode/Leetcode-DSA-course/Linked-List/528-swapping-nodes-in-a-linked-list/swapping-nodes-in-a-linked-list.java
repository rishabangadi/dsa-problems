/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if(head.next==null) return head;
        ListNode beg = head;
        for (int i = 0; i < k - 1; i++)
            beg = beg.next;

        ListNode slow = head, fast = beg.next;
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        int temp = beg.val;
        beg.val = slow.val;
        slow.val = temp;

        return head;
    }
}