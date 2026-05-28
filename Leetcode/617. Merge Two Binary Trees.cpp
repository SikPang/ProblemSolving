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
    void mergeTreeRecur(TreeNode* main, TreeNode* sub){
        if (sub == nullptr) return;

        main->val += sub->val;

        if (sub->left != nullptr){
            if (main->left == nullptr){
                main->left = new TreeNode();
            }
            mergeTreeRecur(main->left, sub->left);
        }

        if (sub->right != nullptr){
            if (main->right == nullptr){
                main->right = new TreeNode();
            }
            mergeTreeRecur(main->right, sub->right);
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;

        TreeNode* mainNode = new TreeNode();

        mergeTreeRecur(mainNode, root1);
        mergeTreeRecur(mainNode, root2);

        return mainNode;
    }
};