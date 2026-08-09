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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* greaterHead = nullptr;
        ListNode* greaterTail = nullptr;

        ListNode* cur = head;
        while (cur != nullptr){
            if (cur->val < x) {
                if (lessHead == nullptr){
                    lessHead = cur;
                    lessTail = cur;
                } else {
                    lessTail->next = cur;
                    lessTail = lessTail->next;
                }
            } else {
                if (greaterHead == nullptr){
                    greaterHead = cur;
                    greaterTail = cur;
                } else {
                    greaterTail->next = cur;
                    greaterTail = greaterTail->next;
                }
            }
            cur = cur->next;
        }

        if (lessTail == nullptr) return greaterHead;
        lessTail->next = greaterHead;
        if (greaterTail != nullptr){
            greaterTail->next = nullptr;
        }
        return lessHead;
    }
};