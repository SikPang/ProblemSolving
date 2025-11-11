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
    void getSumRecur(TreeNode* node, int curSum, int targetSum){
        if (node->left == nullptr && node->right == nullptr){
            if (targetSum == node->val + curSum){
                throw true;
            }
            return;
        }

        if (node->left != nullptr){
            getSumRecur(node->left, curSum + node->val, targetSum);
        }
        if (node->right != nullptr){
            getSumRecur(node->right, curSum + node->val, targetSum);
        }
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }

        try{
            getSumRecur(root, 0, targetSum);
        } catch(bool isTrue){
            return true;
        }
        return false;
    }
};