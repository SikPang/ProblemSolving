class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        vector<int> checker(nums.size());

        for (int i=0; i<nums.size(); ++i){
            ++checker[nums[i]-1];
        }

        for (int i=0; i<checker.size(); ++i){
            if (checker[i] == 0) ret.push_back(i+1);
        }
        return ret;
    }
};