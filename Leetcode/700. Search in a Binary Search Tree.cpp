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
    void searchRecur(TreeNode* cur, int val){
        if (cur->val == val){
            throw cur;
        }

        if (cur->left != nullptr){
            searchRecur(cur->left, val);
        }

        if (cur->right != nullptr){
            searchRecur(cur->right, val);
        }
    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        try{
            searchRecur(root, val);
        } catch(TreeNode* target){
            return target;
        }
        return nullptr;
    }
};