class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int minClosest = INT_MAX;
        int minSum = INT_MAX;

        for (int i=1; i<nums.size()-1; ++i){
            int left = 0;
            int right = nums.size() -1;
            while (left < i && right > i) {
                int sum = nums[left] + nums[i] + nums[right];
                int gap = target-sum;
                if (gap == 0) return sum;

                if (abs(gap) < minClosest){
                    minClosest = abs(gap);
                    minSum = sum;
                }

                if (gap > 0){
                    if (left + 1 < i) ++left;
                    else break;
                } else {
                    if (right - 1 > i) --right;
                    else break;
                }
            }
        }
        return minSum;
    }
};