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
    int subTreeDepth = 0;

    static void CheckEquals(TreeNode* root, TreeNode* subRoot){
        if (root == nullptr && subRoot == nullptr){
            return;
        } else if (root != nullptr && subRoot != nullptr){
            if (root->val != subRoot->val) throw false;
        } else {
            throw false;
        }

        if (root->left == nullptr && subRoot->left == nullptr){
        } else if (root->left != nullptr && subRoot->left != nullptr){
            CheckEquals(root->left, subRoot->left);
        } else {
            throw false;
        }

        if (root->right == nullptr && subRoot->right == nullptr){
        } else if (root->right != nullptr && subRoot->right != nullptr){
            CheckEquals(root->right, subRoot->right);
        } else {
            throw false;
        }
    }

    int GetDepth(TreeNode* cur, TreeNode* subRoot, std::function<void(TreeNode*, TreeNode*)> callBack){
        if (cur == nullptr) return 0;

        int leftChildCount = 0;
        int rightChildCount = 0;

        if (cur->left != nullptr){
            leftChildCount = GetDepth(cur->left, subRoot, callBack);
        }

        if (cur->right != nullptr){
            rightChildCount = GetDepth(cur->right, subRoot, callBack);
        }

        int depth = leftChildCount + rightChildCount + 1;
        if (callBack != nullptr && subTreeDepth == depth){
            try{
                callBack(cur, subRoot);
                throw true;
            } catch (bool a){
                if (a == true) throw true;
            }
        }

        return depth;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subTreeDepth = GetDepth(subRoot, nullptr, nullptr);

        try{
            GetDepth(root, subRoot, CheckEquals);
        } catch (bool){
            return true;
        }
        return false;
    }
};