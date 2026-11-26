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
    void recur(TreeNode* cur, int& sum, int low, int high){
        if (cur == nullptr) return;

        if (cur->val <= high && cur->val >= low){
            sum += cur->val;
        }

        if (cur->left != nullptr){
            recur(cur->left, sum, low, high);
        }

        if (cur->right != nullptr){
            recur(cur->right, sum, low, high);
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        recur(root, sum, low, high);
        return sum;
    }
};