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
    vector<int> nodes;

    void GetAllNodes(TreeNode* cur){
        if (cur == nullptr) return;

        GetAllNodes(cur->left);

        nodes.push_back(cur->val);

        GetAllNodes(cur->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        GetAllNodes(root);
        int minGap = INT_MAX;
        for (int i=0; i<nodes.size()-1; ++i){
            int gap = abs(nodes[i] - nodes[i+1]);
            minGap = min(gap, minGap);
        }
        return minGap;
    }
};