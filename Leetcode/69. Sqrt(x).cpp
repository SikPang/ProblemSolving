class Solution {
public:
    int mySqrt(int x) {
        for (int i=x; i>=0; --i){
            double curSqrt = sqrt(i);

            if (curSqrt - (int)curSqrt == 0.0) return curSqrt;
        }
        return 0;
    }
};