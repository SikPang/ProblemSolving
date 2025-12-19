class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;

        for (int i=0; i<nums.size(); ++i){
            int temp[2] = {nums[i], nums[i]};

            int j=i+1;
            for (; j<nums.size(); ++j) {
                if (abs((long)nums[j] - (long)nums[j-1]) != 1) break;
            }
            temp[1] = nums[j-1];

            ret.push_back(temp[0] == temp[1] ? to_string(temp[0]) : to_string(temp[0]) + "->" + to_string(temp[1]));
            i = j-1;
        }

        return ret;
    }
};