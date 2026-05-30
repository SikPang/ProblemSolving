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
    vector<pair<long, int>> sums;

    void GetSumRecur(TreeNode* node, int depth) {
        if (node == nullptr) return;

        if (sums.size() < depth+1){
            sums.push_back(make_pair(node->val, 1));
        } else {
            sums[depth].first += node->val;
            sums[depth].second += 1;
        }

        GetSumRecur(node->left, depth+1);
        GetSumRecur(node->right, depth+1);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        GetSumRecur(root, 0);

        vector<double> ret(sums.size());
        for (int i=0; i<sums.size(); ++i){
            ret[i] = sums[i].first / (double)sums[i].second;
        }
        return ret;
    }
};