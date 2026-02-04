class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;

        for (int i=0; i<32; ++i){
            bool hasXBit = (x & (1 << i)) != 0;
            bool hasYBit = (y & (1 << i)) != 0;
            if (hasXBit != hasYBit) ++ret;
        }
        return ret;
    }
};