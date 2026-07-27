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
    ListNode* newTail = nullptr;
    ListNode* curTail = nullptr;

    void GetLastNode(ListNode* cur, int& k, int length){
        if (cur == nullptr || cur->next == nullptr) {
            curTail = cur;
            k %= length;
            --k;
            return;
        }

        GetLastNode(cur->next, k, length+1);

        if (newTail != nullptr) return;

        if (k == 0) {
            newTail = cur;
            return;
        }

        if (curTail != nullptr) {
            --k;
            return;
        }
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head;

        GetLastNode(head, k, 1);

        if (newTail == nullptr || curTail == nullptr) return head;

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        curTail->next = head;

        return newHead;
    }
};