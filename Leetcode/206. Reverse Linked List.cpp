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
    ListNode* reverseListRecur(ListNode* cur, ListNode** newList){
        if (cur->next == nullptr){
            *newList = new ListNode(cur->val);
            delete cur;
            return *newList;
        }
        ListNode* newNode = reverseListRecur(cur->next, newList);
        newNode->next = new ListNode(cur->val);
        delete cur;
        return newNode->next;
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = nullptr;
        if (head == nullptr) return ret;

        reverseListRecur(head, &ret);
        return ret;
    }
};