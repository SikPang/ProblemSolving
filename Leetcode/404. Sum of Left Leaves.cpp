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
    void GetSumOfLeftLeaves(TreeNode* cur, int& ret){
        if (cur == nullptr) return;

        if (cur->left != nullptr){
            if (cur->left->left == nullptr && cur->left->right == nullptr){
                ret += cur->left->val;
            } else{
                GetSumOfLeftLeaves(cur->left, ret);
            }
        }

        if (cur->right != nullptr){
            GetSumOfLeftLeaves(cur->right, ret);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        GetSumOfLeftLeaves(root, ret);
        return ret;
    }
};