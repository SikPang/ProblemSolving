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
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;

        set<int> nums;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (bfs.size() > 0){
            TreeNode* cur = bfs.front();
            bfs.pop();

            nums.insert(cur->val);

            if (cur->left != nullptr) {
                bfs.push(cur->left);
            }
            if (cur->right != nullptr){
                bfs.push(cur->right);
            }
        }

        if (nums.size() == 1) return -1;
        auto iter = nums.begin();
        ++iter;
        return *iter;
    }
};