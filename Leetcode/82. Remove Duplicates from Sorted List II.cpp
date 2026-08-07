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
    ListNode* deleteDuplicates(ListNode* head){
        if (head == nullptr) return nullptr;

        ListNode* newHead = head;

        while (newHead && newHead->next){
            bool foundDup = false;
            while (newHead->next && newHead->val == newHead->next->val){
                newHead = newHead->next;
                foundDup = true;
            }
            if (!foundDup) break;

            newHead = newHead->next;
        }

        // cur과 next는 다른 상태
        ListNode* cur = newHead;
        while (cur && cur->next && cur->next->next){
            bool foundDup = false;
            while (cur->next->next && cur->next->val == cur->next->next->val){
                cur->next = cur->next->next;
                foundDup = true;
            }
            if (foundDup){
                cur->next = cur->next->next;
                foundDup = false;
            } else {
                cur = cur->next;
            }
        }
        return newHead;
    }
};