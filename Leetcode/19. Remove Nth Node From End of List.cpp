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
    int maxLen = 0;
    bool RemoveRecur(ListNode* cur, int length, int target){
        if (cur == nullptr) {
            maxLen = length - 1;
            return false;
        }

        bool needRemove = RemoveRecur(cur->next, length + 1, target);
        if (needRemove){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return false;
        }

        if (maxLen - target + 1 == length){
            return true;
        }
        return false;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        RemoveRecur(head, 1, n);
        if (maxLen == 1) return nullptr;
        if (maxLen == n){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        return head;
    }
};