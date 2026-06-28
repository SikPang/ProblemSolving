class Solution {
private:
    void Recur(vector<int>& candidates, set<vector<int>>& mySet, vector<int>& buffer, int target, int curSum, int idx) {
        if (target == curSum){
            mySet.insert(buffer);
        }
        if (curSum >= target) return;

        for (int i=idx; i<candidates.size(); ++i){
            int cur = candidates[i];
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            buffer.push_back(cur);
            Recur(candidates, mySet, buffer, target, curSum + cur, i+1);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        set<vector<int>> mySet;
        vector<int> buffer;

        sort(candidates.begin(), candidates.end());
        Recur(candidates, mySet, buffer, target, 0, 0);
        return vector<vector<int>>(mySet.begin(), mySet.end());
    }
};