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
    int tiltSum = 0;

    int GetTiltSum(TreeNode* cur){
        if (cur == nullptr) return 0;

        int leftSum = GetTiltSum(cur->left);
        int rightSum = GetTiltSum(cur->right);

        tiltSum += abs(leftSum - rightSum);

        return leftSum + rightSum + cur->val;
    }

public:
    int findTilt(TreeNode* root) {
        GetTiltSum(root);
        return tiltSum;
    }
};