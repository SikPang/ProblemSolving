class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);

        ret[0] = 0;
        if (n == 0) return ret;

        ret[1] = 1;
        if (n == 1) return ret;

        int prevCount = 2;
        int curAdditionalNum = 1;
        int counted = 0;

        for (int i=2; i<=n; ++i){
            if (counted == prevCount){
                prevCount = i;
                counted = 0;
            }

            ret[i] = ret[i-prevCount] + 1;
            ++counted;
        }

        return ret;
    }
};