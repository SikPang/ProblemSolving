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
private:
    ListNode* reverseList(ListNode* cur, ListNode* tail) {
        if (cur->next == tail) return cur;

        ListNode* newHead = reverseList(cur->next, tail);

        cur->next->next = cur;
        cur->next = tail;

        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* tail = head;

        for (int i = 0; i < k; ++i) {
            if (tail == nullptr) return head;
            tail = tail->next;
        }

        ListNode* newHead = reverseList(head, tail);

        head->next = reverseKGroup(tail, k);

        return newHead;
    }
};