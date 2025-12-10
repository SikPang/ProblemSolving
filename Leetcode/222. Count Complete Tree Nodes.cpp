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
    int GetCount(TreeNode* cur){
        if (cur == nullptr) return 0;

        int leftCount = 0;
        int rightCount = 0;

        if (cur->left != nullptr) leftCount = GetCount(cur->left);
        if (cur->right != nullptr) rightCount = GetCount(cur->right);

        return leftCount + rightCount + 1;
    }

public:
    int countNodes(TreeNode* root) {
        return GetCount(root);
    }
};