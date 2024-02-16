/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    let slow = head, fast = head, prev = null;
    for (let i = 0; i < n; i++) {
        fast = fast.next;
    }
    while (fast != null) {
        prev = slow;
        slow = slow.next;
        fast = fast.next;
    }
    if (prev == null) {
        head = head.next
        return head
    }
    prev.next = prev.next.next
    return head
};