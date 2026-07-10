class Solution {
private:
    long GetFactorial(int n){
        long ret = 1;
        for (int i=n; i>0; --i){
            ret *= i;
        }
        return ret;
    } 

    void GetPermutation(vector<vector<int>>& ret, vector<int>& nums, vector<int>& buffer, vector<bool>& selected, int depth) {
        if (depth == nums.size()){
            ret.push_back(buffer);
            return;
        }

        for (int i=0; i<nums.size(); ++i) {
            if (selected[i]) continue;

            buffer[depth] = nums[i];
            selected[i] = true;

            GetPermutation(ret, nums, buffer, selected, depth + 1);

            selected[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> buffer(nums.size());
        vector<bool> selected(nums.size());

        long size = GetFactorial(nums.size());
        ret.reserve(size);

        GetPermutation(ret, nums, buffer, selected, 0);
        return ret;
    }
};