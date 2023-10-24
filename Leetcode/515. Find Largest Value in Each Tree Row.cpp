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
    vector<int> largestValues(TreeNode* root) {
        map<int, int> largestValue;
        queue<pair<TreeNode*, int>> que;
        
        que.push(make_pair(root, 0));

        while (!que.empty())
        {
            pair<TreeNode*, int> cur = que.front();
            que.pop();

            if (cur.first == nullptr)
                continue;
            
            auto iter = largestValue.find(cur.second);
            if (iter == largestValue.end())
                largestValue.insert(make_pair(cur.second, cur.first->val));
            else if (iter->second < cur.first->val)
                iter->second = cur.first->val;

            if (cur.first->left)
                que.push(make_pair(cur.first->left, cur.second + 1));
            if (cur.first->right)
                que.push(make_pair(cur.first->right, cur.second + 1));
        }

        vector<int> answer;
        answer.reserve(largestValue.size());
        for (auto iter = largestValue.begin(); iter != largestValue.end(); ++iter)
            answer.push_back(iter->second);
        return answer;
    }
};