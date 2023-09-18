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
    void pushBack(ListNode** head, ListNode** tail, int val){
        ListNode* newNode = new ListNode(val);
        if (*head == nullptr)
        {
            *head = newNode;
            *tail = newNode;
        }
        else
        {
            (*tail)->next = newNode;
            *tail = (*tail)->next;
        }
    }

    int getValue(ListNode** list){
        int val = 0;
        if (*list)
        {
            val = (*list)->val;
            *list = (*list)->next;
        }
        return val;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int prev = 0;
        while (l1 || l2)
        {
            int sum = prev;
            sum += getValue(&l1);
            sum += getValue(&l2);
            prev = sum / 10;
            sum %= 10;
            pushBack(&head, &tail, sum);
        }

        while (prev != 0)
        {
            int val = prev % 10;
            prev /= 10;
            pushBack(&head, &tail, val);
        }
        return head;
    }
};