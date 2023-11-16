class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int dup[65536] = {};

        for (int i=0; i<nums.size(); ++i)
            ++dup[stoi(nums[i], nullptr, 2)];

        for (int i=0; i<65536; ++i)
        {
            if (dup[i] == 0)
                return std::bitset<32>(i).to_string().substr(32-nums.size(), nums.size());
        }
        return string();
    }
};