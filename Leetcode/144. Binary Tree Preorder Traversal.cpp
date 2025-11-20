/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void recur(TreeNode* cur, vector<int>& answer){
        if (cur == nullptr) return;

        answer.push_back(cur->val);
        if (cur->left != nullptr){
            recur(cur->left, answer);
        }
        if (cur->right != nullptr){
            recur(cur->right, answer);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        recur(root, answer);
        return answer;
    }
};