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
    int max = 0;
    int GetDiameter(TreeNode* root){
        int left = 0, right = 0;

        if (root->left != nullptr){
            left += GetDiameter(root->left);
        }

        if (root->right != nullptr){
            right += GetDiameter(root->right);
        }

        max = std::max(left + right, max);
        return std::max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        GetDiameter(root);
        return max;
    }
};