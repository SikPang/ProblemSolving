class Solution {
private:
    void GetSubsetsRecut(vector<int>& nums, vector<int>& buffer, set<vector<int>>& dupChecker, int idx){
        vector<int> temp(buffer.begin(), buffer.end());
        sort(temp.begin(), temp.end());
        dupChecker.insert(temp);

        if (buffer.size() == nums.size()) return;

        for (int i=idx; i<nums.size(); ++i){
            buffer.push_back(nums[i]);
            GetSubsetsRecut(nums, buffer, dupChecker, i+1);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> buffer;
        set<vector<int>> dupChecker;

        GetSubsetsRecut(nums, buffer, dupChecker, 0);
        vector<vector<int>> ret(dupChecker.begin(), dupChecker.end());
        return ret;
    }
};