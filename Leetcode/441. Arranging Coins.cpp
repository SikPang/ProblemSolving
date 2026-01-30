class Solution {
public:
    int arrangeCoins(int n) {
        int completeRow = 0;
        int width = 1;

        while (true) {
            n -= width;
            if (n < 0) break;

            ++width;
            ++completeRow;
        }
        return completeRow;
    }
};