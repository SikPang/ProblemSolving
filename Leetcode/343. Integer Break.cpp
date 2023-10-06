class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        int share = n / 3;
        int remain = n % 3;
        int answer = 1;

        while (share > 0)
        {
            if (remain == 1 && share == 1) break;
            answer *= 3;
            --share;
        }

        int lastPang = share * 3 + remain;
        return lastPang ? answer * lastPang : answer;
    }
};