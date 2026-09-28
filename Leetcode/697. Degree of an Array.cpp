class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> counter(50000);

        for (int i=0; i<nums.size(); ++i){
            counter[nums[i]]++;
        }

        int maxCount = -1;
        for (int i=0; i<counter.size(); ++i){
            maxCount = max(maxCount, counter[i]);
        }

        vector<pair<int, int>> maxNums;
        for (int i=0; i<counter.size(); ++i){
            if (counter[i] == maxCount){
                maxNums.push_back({i, 0});
            }
        }

        for (int i=0; i<maxNums.size(); ++i){
            int start = -1;
            int end = -1;
            for (int j=0; j<nums.size(); ++j){
                if (nums[j] == maxNums[i].first){
                    if (start == -1){
                        start = j;
                        end = j;
                    } else {
                        end = j;
                    }
                }
            }
            maxNums[i].second = end-start+1;
        }

        pair<int, int> minPair{0, INT_MAX};
        for (int i=0; i<maxNums.size(); ++i){
            if (minPair.second > maxNums[i].second){
                minPair = maxNums[i];
            }
        }
        return minPair.second;
    }
};