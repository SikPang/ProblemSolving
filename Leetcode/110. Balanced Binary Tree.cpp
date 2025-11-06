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
    int CheckChildrensHegiht(TreeNode* cur, int depth){
        if (cur == nullptr) return 0;

        int leftHeight = CheckChildrensHegiht(cur->left, depth + 1);
        int rightHeight = CheckChildrensHegiht(cur->right, depth + 1);

        if (abs(leftHeight - rightHeight) > 1) throw false;

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        try{
            CheckChildrensHegiht(root, 0);
        } catch (bool isHeightBalanced){
            return isHeightBalanced;
        }
        return true;
    }
};