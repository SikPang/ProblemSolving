class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minWidth = m;
        int minHeight = n;

        for (int i=0; i<ops.size(); ++i) {
            minWidth = min(ops[i][0], minWidth);
            minHeight = min(ops[i][1], minHeight);
        }
        return minWidth * minHeight;
    }
};