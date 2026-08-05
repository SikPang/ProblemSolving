class Solution {
private:
    void pull(vector<int>& nums, int cur, int last){
        int prev = nums[cur];
        for (int i=cur; i<last && i+1 <nums.size(); ++i){
            nums[i] = nums[i+1];
        }
        nums[cur] = prev;
    }

public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int cur = nums[nums.size()-1];
        int count = 1;

        for (int i=nums.size()-2; i>=0; --i){
            if (nums[i] == cur){
                ++count;
                if (count > 2){
                    pull(nums, i, len);
                    --len;
                }
            } else {
                cur = nums[i];
                count = 1;
            }
        }
        return len;
    }
};