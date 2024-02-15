# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if right==1: 
            return head
        l=None
        r=None
        start=head
        for i in range(left-1):
            l=start
            start=start.next
        
        end=start
        for i in range(right-left):
            end=end.next
        
        r=end.next
        prev=r
        while start!=r:
            nextNode=start.next
            start.next=prev
            prev=start
            start=nextNode

        if l != None: 
            l.next=end
        
        if l==None:
            return end
        return head


