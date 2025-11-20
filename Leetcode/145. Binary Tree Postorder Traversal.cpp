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

        if (cur->left != nullptr){
            recur(cur->left, answer);
        }
        if (cur->right != nullptr){
            recur(cur->right, answer);
        }
        answer.push_back(cur->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        recur(root, answer);
        return answer;
    }
};