class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0;
        int lStreak = 0;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == 'L') {
                ++lStreak;
                if (lStreak == 3) return false;
            } else {
                if (s[i] == 'A') {
                    ++aCount;
                    if (aCount == 2) return false;
                }
                lStreak = 0;
            }
        }
        return true;
    }
};