class Solution {
public:
    int divide(int dividend, int divisor) {
        long answer = 0;
        int minus = dividend < 0 ? (divisor < 0 ? 1 : -1) : (divisor < 0 ? -1 : 1);
        long dividendLong = abs((long)dividend);
        long divisorLong = abs((long)divisor);
        
        while (dividendLong >= divisorLong) {
            long temp = divisorLong;
            long multiple = 1;

            while (dividendLong >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dividendLong -= temp;
            answer += multiple;
        }
        return clamp(answer * minus, (long)INT_MIN, (long)INT_MAX);
    }
};