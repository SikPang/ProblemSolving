class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> answer(nums.size());
        int oddIdx = 1;
        int evenIdx = 0;

        for (int i=0; i<nums.size(); ++i){
            if (nums[i] % 2 == 0) {
                answer[evenIdx] = nums[i];
                evenIdx += 2;
            } else {
                answer[oddIdx] = nums[i];
                oddIdx += 2;
            }
        }
        return answer;
    }
};