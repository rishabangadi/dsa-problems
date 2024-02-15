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

function swapPairs(head: ListNode | null): ListNode | null {
    if (!head || !head.next)
        return head;
    let prev = null;
    let dummy = head.next;
    while (head && head.next) {
        if (prev) prev.next = head.next;
        prev = head;
        let nextNode = head.next.next;
        head.next.next = head;
        head.next = nextNode;
        head = nextNode;
    }
    return dummy;
};