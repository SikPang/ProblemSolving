class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        unsigned long long cur = 0;
        unsigned long long target = accumulate(nums.begin(), nums.end(), 0) - x;
        int answer = INT_MAX;
		int startIdx = 0, endIdx = 0;

        while (true)
        {
            if (cur > target)
                cur -= nums[startIdx++];
            else
			{
				if (endIdx == nums.size()) break;
                cur += nums[endIdx++];
			}

            if (cur == target)
                answer = min(answer, (int)nums.size() - (endIdx - startIdx));
        }
        if (answer == INT_MAX)
            return -1;
        return answer;
    }
};