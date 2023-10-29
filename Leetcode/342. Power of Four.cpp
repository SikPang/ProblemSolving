class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;

        while (n > 0)
        {
            if (n % 4 != 0)
                return false;
            if (n / 4 == 1)
                return true;
            n /= 4;
        }
        return false;
    }
};