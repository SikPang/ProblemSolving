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
        if (head == nullptr) return head;

        ListNode* curFirst = head;
        ListNode* curSecond = head->next;
        ListNode* prev = nullptr;

        if (curSecond != nullptr){
            head = head->next;
        }

        while (curFirst != nullptr && curSecond != nullptr){
            ListNode* next = curSecond->next;
            
            if (prev != nullptr){
                prev->next = curSecond;
            }
            curSecond->next = curFirst;
            curFirst->next = next;

            prev = curFirst;
            curFirst = next;
            if (curFirst != nullptr){
                curSecond = curFirst->next;
            }
        }
        return head;
    }
};