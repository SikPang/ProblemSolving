class Solution {
private:
    void GetPermutation(set<vector<int>>& ret, vector<int>& nums, vector<int>& buffer, vector<bool>& used, int depth){
        if (depth == nums.size()){
            ret.insert(buffer);
            return;
        }

        for (int i=0; i<nums.size(); ++i){
            if (used[i]) continue;

            buffer[depth] = nums[i];
            used[i] = true;
            GetPermutation(ret, nums, buffer, used, depth+1);
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> buffer(nums.size());
        vector<bool> used(nums.size());

        GetPermutation(ret, nums, buffer, used, 0);
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};