class Solution {
private:
    void subsetsRecur(vector<vector<int>>& ret, vector<int>& nums, vector<int>& buffer, int idx){
        ret.push_back(buffer);

        if (buffer.size() == nums.size()){
            return;
        }

        for (int i=idx; i<nums.size(); ++i){
            buffer.push_back(nums[i]);
            subsetsRecur(ret, nums, buffer, i+1);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> buffer;

        subsetsRecur(ret, nums, buffer, 0);
        return ret;
    }
};