/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void preorderTraversal(Node* cur, vector<int>& answer){
        if (cur == nullptr) return;

        answer.push_back(cur->val);
        for (int i=0; i<cur->children.size(); ++i){
            preorderTraversal(cur->children[i], answer);
        }
    }

public:
    vector<int> preorder(Node* root) {
        vector<int> answer;
        preorderTraversal(root, answer);
        return answer;
    }
};