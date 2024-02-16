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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = nullptr, *end = nullptr, *curr = head;
        int prev = -111;
        while (curr->next != nullptr) {
            if (prev != curr->val && curr->val != curr->next->val) {
                if (newHead == nullptr) {
                    newHead = curr;
                    end = curr;
                } else {
                    end->next = curr;
                    end = curr;
                }
            } else {
                prev = curr->val;
            }
            curr = curr->next;
        }
        if (curr->val != prev) {
            if (end)
                end->next = curr;
            else newHead=curr;
        } else {
            if (end)
                end->next = nullptr;
        }
        return newHead;
    }
};