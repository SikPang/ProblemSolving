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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedListHead = nullptr;
        ListNode* iter = mergedListHead;

        while (list1 != nullptr || list2 != nullptr){
            ListNode* nextNode = nullptr;
            if (list2 == nullptr || (list1 != nullptr && list1->val <= list2->val)){
                nextNode = new ListNode(list1->val);
                list1 = list1->next;
            } else{
                nextNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (iter == nullptr){
                mergedListHead = iter = nextNode;
            } else{
                iter->next = nextNode;
                iter = iter->next;
            }
        }
        return mergedListHead;
    }
};