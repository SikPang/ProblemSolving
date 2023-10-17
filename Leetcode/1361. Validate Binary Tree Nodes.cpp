class Solution {
private:
    void dfs(vector<int>& leftChild, vector<int>& rightChild, set<int>& dup, int curNode)
    {
        if (dup.find(curNode) != dup.end())
            throw 0;
        
        dup.insert(curNode);

        if (leftChild[curNode] != -1)
            dfs(leftChild, rightChild, dup, leftChild[curNode]);
        if (rightChild[curNode] != -1)
            dfs(leftChild, rightChild, dup, rightChild[curNode]);
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int rootNode = -1;

        {
            vector<int> dup(n);
            for (int i=0; i<n; ++i)
            {
                if (leftChild[i] != -1)
                    dup[leftChild[i]] = 1;
                if (rightChild[i] != -1)
                    dup[rightChild[i]] = 1;
            }
            for (int i=0; i<n; ++i)
            {
                if (dup[i] == 0)
                    rootNode = i;
            }
        }

        if (rootNode == -1)
            return false;

        set<int> dup;
        try{
            dfs(leftChild, rightChild, dup, rootNode);
        }catch(int err){
            return false;
        }
        
        if (dup.size() != n)
            return false;
        return true;
    }
};