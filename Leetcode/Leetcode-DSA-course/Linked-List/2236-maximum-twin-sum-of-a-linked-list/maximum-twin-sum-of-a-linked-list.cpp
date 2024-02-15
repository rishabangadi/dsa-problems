/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    int pairSum(ListNode* head) {
        ListNode* mid = getMiddle(head);
        // Reverse the second half of linkedlist
        ListNode *prev = nullptr, *nextNode = nullptr;
        while (mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        int maxSum = 0;
        ListNode* start = head;
        while (prev) {
            maxSum = max(maxSum, start->val + prev->val);
            start = start->next;
            prev = prev->next;
        }
        return maxSum;
    }
};