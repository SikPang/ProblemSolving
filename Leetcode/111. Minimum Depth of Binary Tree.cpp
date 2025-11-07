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
    int curMinDepth = 2147483647;

    void findMinDepth(TreeNode* node, int depth){
        if (node->left == nullptr && node->right == nullptr){
            curMinDepth = min(depth, curMinDepth);
            return;
        }

        if (node->left != nullptr){
            findMinDepth(node->left, depth + 1);
        }
        if (node->right != nullptr){
            findMinDepth(node->right, depth + 1);
        }
    }

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        findMinDepth(root, 1);
        return curMinDepth;
    }
};