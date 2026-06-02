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
    unordered_set<int> values;
    void FindTargetRecur(TreeNode* root, int k){
        if (root == nullptr) return;
        if (values.find(k - root->val) != values.end()) throw true;

        values.insert(root->val);

        FindTargetRecur(root->left, k);
        FindTargetRecur(root->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        try{
            FindTargetRecur(root, k);
        } catch (bool found){
            return true;
        }
        return false;
    }
};