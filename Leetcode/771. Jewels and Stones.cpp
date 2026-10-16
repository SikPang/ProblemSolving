class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        array<bool, 58> jewelSet;
        int answer = 0;

        for (int i=0; i<jewels.size(); ++i){
            jewelSet[jewels[i]-'A'] = true;
        }

        for (int i=0; i<stones.size(); ++i){
            answer += jewelSet[stones[i]-'A'] ? 1 : 0;
        }
        return answer;
    }
};