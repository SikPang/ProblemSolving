class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        vector<int> answer;
        float target = nums.size() / 3.f;

        for (int i=0; i<nums.size(); ++i)
            ++counter[nums[i]];

        for (unordered_map<int, int>::iterator iter=counter.begin(); iter!=counter.end(); ++iter)
        {
            if (iter->second > target)
                answer.push_back(iter->first);
        }
        return answer;
    }
};