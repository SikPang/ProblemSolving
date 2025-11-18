/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<ListNode*> set;

public:
    bool hasCycle(ListNode *head) {
        while (head != nullptr && head->next != nullptr){
            if (set.find(head) == set.end()){
                set.insert(head);
            } else{
                return true;
            }
            head = head->next;
        }
        return false;
    }
};