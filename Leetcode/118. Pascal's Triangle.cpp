class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows, vector<int>());
        ret[0].push_back(1);
        if (numRows == 1) return ret;

        for (int i=1; i<numRows; ++i){
            auto& prev = ret[i-1];
            auto& cur = ret[i];

            cur.push_back(1);
            for (int j=0; j<prev.size()-1; ++j){
                cur.push_back(prev[j] + prev[j+1]);
            }
            cur.push_back(1);
        }
        return ret;
    }
};