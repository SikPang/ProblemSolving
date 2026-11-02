class Solution {
public:
    int binaryGap(int n) {
        int maxLen = INT_MIN;
        int cur = -1;
        int i = 0;

        while (n > 0){
            if (n % 2 == 1){
                if (cur != -1 && maxLen < i - cur){
                    maxLen = i - cur;
                }
                cur = i;
            }
            ++i;
            n /= 2;
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};