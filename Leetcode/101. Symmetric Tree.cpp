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
    const int NullValue = -2147483648;
    void recursion(vector<int>& ret, TreeNode* node, int factor, bool isLeftSubTree) {
        if (node == nullptr) {
            ret.push_back(NullValue);
            return;
        }

        recursion(ret, node->left, isLeftSubTree ? 1 : 2, isLeftSubTree);
        ret.push_back(node->val + factor);
        recursion(ret, node->right, isLeftSubTree ? 2 : 1, isLeftSubTree);
    }

public:
    bool isSymmetric(TreeNode* root) {
        vector<int> leftVec;
        recursion(leftVec, root->left, 1, true);

        vector<int> rightVec;
        recursion(rightVec, root->right, 1, false);

        if (leftVec.size() != rightVec.size()) return false;

        for (int i=0; i<leftVec.size(); ++i){
            if (leftVec[i] != rightVec[rightVec.size()-1-i]) return false;
        }
        return true;
    }
};