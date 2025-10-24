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
    void recursion(vector<int>& ret, TreeNode* node) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr){
            ret.push_back(node->val);
            return;
        }

        recursion(ret, node->left);
        ret.push_back(node->val);
        recursion(ret, node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        recursion(ret, root);
        return ret;
    }
};