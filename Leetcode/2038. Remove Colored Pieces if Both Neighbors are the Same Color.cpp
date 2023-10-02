class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int aCnt = 0, bCnt = 0, curLen = 1;
        char prev = colors.front();

        for (int i=1; i<colors.length(); ++i)
        {
            if (colors[i] != prev)
            {
                if (curLen >= 3)
                    prev == 'A' ? aCnt += curLen - 2 : bCnt += curLen - 2;
                prev = colors[i];
                curLen = 0;
            }
            ++curLen;
        }
        if (curLen >= 3)
            prev == 'A' ? aCnt += curLen - 2 : bCnt += curLen - 2;

        if (aCnt <= bCnt)
            return false;
        return true;
    }
};