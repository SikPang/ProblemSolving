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
    void insert(TreeNode** root, TreeNode* cur, int target){
        if (*root == nullptr){
            *root = new TreeNode(target);
            return;
        }

        if (cur->right != nullptr){
            insert(root, cur->right, target);
        } else {
            cur->right = new TreeNode(target);
        }
    }

    void rearrangeRecur(TreeNode* origin, TreeNode** newT){
        if (origin->left != nullptr){
            rearrangeRecur(origin->left, newT);
        }

        insert(newT, *newT, origin->val);

        if (origin->right != nullptr){
            rearrangeRecur(origin->right, newT);
        }
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ret = nullptr;
        rearrangeRecur(root, &ret);
        return ret;
    }
};