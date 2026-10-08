class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        pair<int, int> firstBig(-1, -1);
        pair<int, int> secondBig(-1, -1);

        for (int i=0; i<nums.size(); ++i){
            if (firstBig.second < nums[i]){
                secondBig = firstBig;
                firstBig = make_pair(i, nums[i]);
            } else if (secondBig.second < nums[i]){
                secondBig = make_pair(i, nums[i]);
            }
        }
        return firstBig.second >= secondBig.second * 2 ? firstBig.first : -1;
    }
};