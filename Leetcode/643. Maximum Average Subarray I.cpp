class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg;
        long avg = 0;

        int left = 0;
        int right = k-1;

        for (int i=left; i<=right; ++i){
            avg += nums[i];
        }
        maxAvg = avg / (double)k;

        for (; right < nums.size() - 1;){
            avg -= nums[left++];
            avg += nums[++right];
            double curAvg = avg / (double)k;
            maxAvg = max(maxAvg, curAvg);
        }
        return maxAvg;
    }
};