class Solution {
public:
    int findComplement(int num) {
        string bits(32, '0');

        int largeBitIdx = 32;
        for (int i=0; i<32; ++i){
            bool hasBit = (num & (1 << i)) != 0;
            bits[32-1-i] = hasBit ? '0' : '1';
            largeBitIdx = hasBit ? min(32-1-i, largeBitIdx) : largeBitIdx;
        }

        int answer = 0;
        for (int i=largeBitIdx; i<32; ++i){
            if (bits[i] == '0') continue;
            answer += (1 << (32-1-i));
        }
        return answer;
    }
};