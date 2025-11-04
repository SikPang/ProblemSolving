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
    void Insert(TreeNode** root, int value){
        if (*root == nullptr){
            *root = new TreeNode(value);
            return;
        }

        if (value > (*root)->val){
            if ((*root)->right == nullptr){
                (*root)->right = new TreeNode(value);
            } else{
                Insert(&((*root)->right), value);
            }
        } else if (value < (*root)->val){
            if ((*root)->left == nullptr){
                (*root)->left = new TreeNode(value);
            } else{
                Insert(&((*root)->left), value);
            }
        }
    }

    void InsertElemsRecur(vector<int>& nums, TreeNode** root, int left, int middle, int right){
        Insert(root, nums[middle]);

        if (middle == left || middle == right) return;

        // left ~ middle
        InsertElemsRecur(nums, root, left, (middle + left) / 2.0f, middle);
        // middle ~ right
        InsertElemsRecur(nums, root, middle, (middle + right) / 2.0f, right);
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int middle = (int)(nums.size() / 2.0f);
        TreeNode* root = nullptr;

        InsertElemsRecur(nums, &root, 0, middle, nums.size());
        
        return root;
    }
};