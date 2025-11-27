class Solution {
public:
    int reverseBits(int n) {
        int answer = 0;
        for (int i=0; i<32; ++i){
            bool hasBit = (n & (1 << (31 - i))) > 0;
            answer += hasBit ? pow(2, i) : 0;
        }
        return answer;
    }
};