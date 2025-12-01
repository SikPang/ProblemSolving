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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;

        while (cur != nullptr && cur->val == val){
            ListNode* temp = cur;
            cur = cur->next;
            delete temp;
            head = cur;
        }

        while (cur != nullptr && cur->next != nullptr){
            if (cur->next->val == val){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                continue;
            }
            cur = cur->next;
        }
        return head;
    }
};