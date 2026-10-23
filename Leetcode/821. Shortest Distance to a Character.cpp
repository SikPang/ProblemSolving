class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer(s.size());
        deque<int> targetIndices;

        for (int i=0; i<s.size(); ++i){
            if (s[i] == c) {
                targetIndices.push_back(i);
            }
        }

        for (int i=0; i<s.size(); ++i){
            int firstGap = abs(targetIndices[0] - i);
            int secondGap = abs(targetIndices[1] - i);

            if (firstGap < secondGap){
                answer[i] = firstGap;
            } else {
                answer[i] = secondGap;
                targetIndices.pop_front();
            }
        }
        return answer;
    }
};