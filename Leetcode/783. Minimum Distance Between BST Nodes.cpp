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
    int minGap = INT_MAX;
    int prevNum = -1;

    void findMinGap(TreeNode* node){
        if (node->left != nullptr){
            findMinGap(node->left);
        }

        if (prevNum != -1){
            minGap = min(minGap, node->val - prevNum);
        }
        prevNum = node->val;

        if (node->right != nullptr){
            findMinGap(node->right);
        }
    }

public:
    int minDiffInBST(TreeNode* root) {
        findMinGap(root);
        return minGap;
    }
};