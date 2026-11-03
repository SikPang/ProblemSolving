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
    void GetSequenceRecur(vector<int>& sequence, TreeNode* cur){
        if (cur->left == nullptr && cur->right == nullptr){
            sequence.push_back(cur->val);
            return;
        }

        if (cur->left != nullptr){
            GetSequenceRecur(sequence, cur->left);
        }

        if (cur->right != nullptr){
            GetSequenceRecur(sequence, cur->right);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;

        GetSequenceRecur(seq1, root1);
        GetSequenceRecur(seq2, root2);

        if (seq1.size() != seq2.size()) return false;
        for (int i=0; i<seq1.size(); ++i){
            if (seq1[i] != seq2[i]) return false;
        }
        return true;
    }
};