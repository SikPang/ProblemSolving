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
    unordered_map<int, int> nums;

    void findModeRecur(TreeNode* cur){
        if (cur == nullptr) return;

        nums[cur->val]++;

        findModeRecur(cur->left);
        findModeRecur(cur->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        findModeRecur(root);

        vector<int> ret;
        int maxCount = 0;

        for (auto iter = nums.begin(); iter != nums.end(); ++iter){
            if (maxCount < iter->second){
                maxCount = iter->second;
                ret.clear();
                ret.push_back(iter->first);
            } else if (maxCount == iter->second){
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
};