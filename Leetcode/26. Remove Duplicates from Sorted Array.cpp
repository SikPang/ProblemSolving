class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> dupChecker;

        for (int i=0; i<nums.size(); ++i){
            dupChecker.insert(nums[i]);
        }

        nums.clear();

        for (set<int>::iterator iter=dupChecker.begin(); iter!=dupChecker.end(); ++iter){
            nums.push_back(*iter);
        }
        return dupChecker.size();
    }
};