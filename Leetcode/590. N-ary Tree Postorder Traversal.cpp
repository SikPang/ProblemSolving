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
    void postorderTraversal(Node* cur, vector<int>& answer){
        if (cur == nullptr) return;

        for (int i=0; i<cur->children.size(); ++i){
            Node* curChild = cur->children[i];
            postorderTraversal(curChild, answer);
            answer.push_back(curChild->val);
        }
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> answer;
        postorderTraversal(root, answer);
        if (root != nullptr){
            answer.push_back(root->val);
        }
        return answer;
    }
};