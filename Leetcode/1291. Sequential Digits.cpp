class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        int start = 1;
        int cur = 1;
        while (start <= 10){
            for (int i=start+1; i<=9; ++i){
                cur *= 10;
                cur += i;
                if (cur >= low && cur <= high){
                    ret.push_back(cur);
                }
                if (cur >= high) break;
            }
            ++start;
            cur = start;
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};