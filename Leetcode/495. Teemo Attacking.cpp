class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration;
        int size = timeSeries.size();

        for (int i=0; i<size-1; ++i){
            int gap = timeSeries[i + 1] - timeSeries[i];
            total += gap > duration ? duration : gap;
        }
        return total;
    }
};