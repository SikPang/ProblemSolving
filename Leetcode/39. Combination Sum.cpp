class Solution {
private:
    void Recur(vector<int>& candidates, set<vector<int>>& mySet, vector<int>& buffer, int target, int curSum) {
        if (target == curSum){
            vector<int> add(buffer.begin(), buffer.end());
            sort(add.begin(), add.end());
            mySet.insert(add);
        }
        if (curSum >= target) return;

        for (int i=0; i<candidates.size(); ++i){
            int cur = candidates[i];
            buffer.push_back(cur);
            curSum += cur;
            Recur(candidates, mySet, buffer, target, curSum);
            curSum -= cur;
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        set<vector<int>> mySet;
        vector<int> buffer;

        Recur(candidates, mySet, buffer, target, 0);
        return vector<vector<int>>(mySet.begin(), mySet.end());
    }
};