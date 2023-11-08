class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Chebyshev distance = max(x2 - x1, y2 - y1)
        if (max(abs(fx - sx), abs(fy - sy)) > t 
            || (fx == sx && fy == sy && t == 1))
            return false;
        return true;
    }
};