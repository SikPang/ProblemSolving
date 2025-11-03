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
    int mDepth;

    void GetMaxDepthRecur(TreeNode* node, int depth){
        if (node == nullptr) return;

        mDepth = depth > mDepth ? depth : mDepth;
        GetMaxDepthRecur(node->left, depth + 1);
        GetMaxDepthRecur(node->right, depth + 1);
    }

public:
    int maxDepth(TreeNode* root) {
        mDepth = 0;

        GetMaxDepthRecur(root, 1);
        return mDepth;
    }
};