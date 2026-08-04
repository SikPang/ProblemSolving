class Solution {
private:
    void combineRecur(vector<vector<int>>& ret, vector<int>& nums, vector<int>& buffer, int k, int depth, int idx){
        if (depth == buffer.size()){
            ret.push_back(buffer);
            return;
        }

        for (int i=idx; i<nums.size(); ++i){
            buffer[depth] = nums[i];
            combineRecur(ret, nums, buffer, k, depth+1, i+1);
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> nums(n);
        vector<bool> isUsed(n);
        vector<int> buffer(k);

        for (int i=0; i<n; ++i){
            nums[i] = i+1;
        }
        combineRecur(ret, nums, buffer, k, 0, 0);
        return ret;
    }
};