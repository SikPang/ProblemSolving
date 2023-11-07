class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        time.reserve(dist.size());

        // 시 = 거 / 속
        for (int i=0; i<dist.size(); ++i)
            time.push_back((double)dist[i] / speed[i]);

        sort(time.begin(), time.end());

        for (int i=0, cur=0; i<time.size(); ++i, ++cur)
        {
            if (cur >= time[i])
                return i;
        }
        return time.size();
    }
};