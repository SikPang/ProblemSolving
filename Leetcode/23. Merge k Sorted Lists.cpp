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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;

        while (true){
            bool isDone = true;
            ListNode** curMinNode = nullptr;

            for (int i=0; i<lists.size(); ++i){
                if (lists[i] == nullptr) continue;

                isDone = false;
                if (curMinNode == nullptr || lists[i]->val < (*curMinNode)->val){
                    curMinNode = &lists[i];
                }
            }
            if (isDone) return ret;

            if (ret == nullptr){
                ret = *curMinNode;
                cur = ret;
            } else {
                cur->next = *curMinNode;
                cur = cur->next;
            }
            *curMinNode = (*curMinNode)->next;
        }
    }
};