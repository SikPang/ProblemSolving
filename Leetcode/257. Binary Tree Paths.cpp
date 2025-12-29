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
    vector<string> ret;

    void AddPathRecur(TreeNode* curNode, string curStr){
        if (curNode == nullptr) return;

        if (curNode->left == nullptr && curNode->right == nullptr){
            ret.push_back(curStr);
            return;
        }

        if (curNode->left != nullptr){
            AddPathRecur(curNode->left, curStr + "->" + to_string(curNode->left->val));
        }
        if (curNode->right != nullptr){
            AddPathRecur(curNode->right, curStr + "->" + to_string(curNode->right->val));
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ret = vector<string>();

        if (root == nullptr) return ret;

        AddPathRecur(root, to_string(root->val));

        return ret;
    }
};