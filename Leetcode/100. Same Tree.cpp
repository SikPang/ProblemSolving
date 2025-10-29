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
    void recursion(vector<int>& ret, TreeNode* node) {
        if (node == nullptr) {
            ret.push_back(NullValue);
            return;
        }

        ret.push_back(node->val);
        recursion(ret, node->left);
        recursion(ret, node->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ret1;
        recursion(ret1, p);

        vector<int> ret2;
        recursion(ret2, q);

        if (ret1.size() != ret2.size()) return false;

        for (int i=0; i<ret1.size(); ++i){
            if (ret1[i] != ret2[i]) return false;
        }
        return true;
    }
};