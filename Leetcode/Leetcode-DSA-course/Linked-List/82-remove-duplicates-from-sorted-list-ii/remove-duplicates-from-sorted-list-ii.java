/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // Sentinel
        ListNode sentinel = new ListNode(0, head);

        // predecessor = the last node 
        // before the sublist of duplicates
        ListNode pred = sentinel;
        
        while (head != null) {
            // If it's a beginning of the duplicates sublist 
            // skip all duplicates
            if (head.next != null && head.val == head.next.val) {
                // Move till the end of the duplicates sublist
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;    
                }

                // Skip all duplicates
                pred.next = head.next;
    
            // otherwise, move predecessor
            } else {
                pred = pred.next;    
            }
                
            // move forward
            head = head.next;    
        }  
        return sentinel.next;
    }
}