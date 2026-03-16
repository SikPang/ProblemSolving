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
    int maxDep = 0;

    void GetMaxDepth(Node* cur, int depth){
        if (cur == nullptr) return;

        maxDep = max(depth, maxDep);
        for (int i=0; i<cur->children.size(); ++i){
            GetMaxDepth(cur->children[i], depth + 1);
        }
    }

public:
    int maxDepth(Node* root) {
        GetMaxDepth(root, 1);
        return maxDep;
    }
};