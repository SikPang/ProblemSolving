class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    answer.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    --right;
                    while (right >= 0 && nums[right] == nums[right+1]) --right;

                    ++left;
                    while (left < nums.size() && nums[left] == nums[left-1]) ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return answer;
    }
};