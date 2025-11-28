class Solution {
public:
    int hammingWeight(int n) {
        int answer = 0;

        for (int i=0; i<32; ++i){
            answer += ((1 << i) & n) > 0 ? 1 : 0;
        }
        return answer;
    }
};