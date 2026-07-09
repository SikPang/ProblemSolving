class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int jumpCount = 0;
        int idx = 0;

        while (idx <= nums.size()-1){
            int curNum = nums[idx];
            if (idx + curNum >= nums.size()-1) return ++jumpCount;

            if (curNum == 0){
                ++idx;
                ++jumpCount;
                continue;
            }

            int maxJump = 1;
            int maxJ = curNum;

            for (int j=1; j<=curNum; ++j){
                int candidate = j + nums[idx + j];
                if (maxJump < candidate){
                    maxJump = candidate;
                    maxJ = j;
                }
                maxJump = max(maxJump, candidate);
            }

            idx += maxJ;
            ++jumpCount;
        }
        return jumpCount;
    }
};