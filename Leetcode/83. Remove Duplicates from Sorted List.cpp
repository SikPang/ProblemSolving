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
        ListNode* cur = head;

        while (cur != nullptr && cur->next != nullptr){
            ListNode* next = cur->next;
            if (cur->val == next->val){
                cur->next = cur->next->next;
                delete next;
            } else{
                cur = cur->next;
            }
        }
        return head;
    }
};