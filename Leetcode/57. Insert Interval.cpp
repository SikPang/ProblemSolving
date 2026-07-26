class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        intervals.push_back(vector<int>{100001, 100001});

        vector<int> cur = intervals[0];
        for (int i=1; i<intervals.size(); ++i){
            if (intervals[i][0] > cur[1]) {
                ret.push_back(cur);
                cur = intervals[i];
            } else {
                cur[1] = max(cur[1], intervals[i][1]);
            }
        }
        return ret;
    }
};