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
    int totalSize;

    void CheckPalindromeRecur(ListNode* cur, stack<int>& validator, int depth){
        if (cur == nullptr) return;

        ++totalSize;
        CheckPalindromeRecur(cur->next, validator, depth+1);

        if (totalSize % 2 != 0 && depth == totalSize/2 + 1){
            return;
        } else if (depth > totalSize/2){
            validator.push(cur->val);
        } else {
            if (validator.empty()) return;

            int topVal = validator.top();
            if (cur->val != topVal) return;

            validator.pop();
        }
    }

public:
    bool isPalindrome(ListNode* head) {
        stack<int> validator;
        
        totalSize = 0;
        CheckPalindromeRecur(head, validator, 1);

        return head != nullptr && validator.empty();
    }
};