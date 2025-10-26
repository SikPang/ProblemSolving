class Solution {
public:
    string addBinary(string a, string b) {
        string& longs = a.size() > b.size() ? a : b;
        string& shorts = a.size() > b.size() ? b : a;
        string newShorts(longs.size() - shorts.size(), '0');
        newShorts.append(shorts);
        int increaseCnt = 0;

        for (int i=longs.size()-1; i>=0; --i){
            int curSum = 0;
            if (increaseCnt > 0){
                --increaseCnt;
                ++curSum;
            }
            curSum += (longs[i] - '0') + (newShorts[i] - '0');

            if (curSum >= 2){
                ++increaseCnt;
            }
            longs[i] = curSum % 2 == 0 ? '0' : '1';
        }

        if (increaseCnt == 1){
            longs.insert(longs.begin(), '1');
        } else if (increaseCnt == 2){
            longs.insert(longs.begin(), '0');
            longs.insert(longs.begin(), '1');
        }
        return longs;
    }
};