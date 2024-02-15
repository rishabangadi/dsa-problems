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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* dummy = head->next;
        while (head != nullptr && head->next != nullptr) {
            if (prev != nullptr)
                prev->next = head->next;
            prev = head;

            ListNode* nextNode = head->next->next;
            head->next->next = head;
            head->next = nextNode;
            head = nextNode;
        }
        return dummy;
    }
};