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
    int len = 0;

    ListNode* GetMiddleNode(ListNode* node, int cur){
        if (node == nullptr) return nullptr;

        ++len;
        ListNode* middle = GetMiddleNode(node->next, cur + 1);

        if (middle != nullptr) return middle;
        if (cur == len / 2 + 1) return node;
        return nullptr;
    }

public:
    ListNode* middleNode(ListNode* head) {
        return GetMiddleNode(head, 1);
    }
};