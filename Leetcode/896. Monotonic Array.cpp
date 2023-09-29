class Solution {
private:
    enum State
    {
        None, Increase, Decrease
    };

public:
    bool isMonotonic(vector<int>& nums) {
        State state = None;
        
        for (int i=1; i<nums.size(); ++i)
        {
            if (state == None && nums[i] > nums[i-1])
                state = Increase;
            else if (state == None && nums[i] < nums[i-1])
                state = Decrease;
            else if (state == Increase && nums[i] < nums[i-1])
               return false;
            else if (state == Decrease && nums[i] > nums[i-1])
                return false;
        }
        return true;
    }
};