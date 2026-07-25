class Solution {
private:
    void JumpRecur(vector<int>& nums, vector<bool>& isVisited, int curIdx){
        if (curIdx == nums.size()-1) throw true;

        for (int i=curIdx+1; i<=curIdx+nums[curIdx] && i<nums.size(); ++i){
            if (isVisited[i]) continue;
            isVisited[i] = true;
            JumpRecur(nums, isVisited, i);
        }
    }

public:
    bool canJump(vector<int>& nums) {
        vector<bool> isVisited(nums.size());
        try{
            JumpRecur(nums, isVisited, 0);
        } catch(bool res){
            return true;
        }
        return false;
    }
};