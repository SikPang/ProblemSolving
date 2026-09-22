class Solution {
public:
    int countBinarySubstrings(string s) {
        int answer = 0;
        char prevChar = s[0];
        int prevCount = 1;
        int startIdx = 1;

        for (startIdx=1; startIdx<s.size(); ++startIdx){
            if (s[startIdx] == prevChar){
                ++prevCount;
            } else {
                break;
            }
        }

        if (startIdx >= s.size()) return answer;

        char curChar = s[startIdx];
        int curCount = 1;
        for (int i=startIdx+1; i<s.size(); ++i){
            if (curChar == s[i]){
                ++curCount;
            } else {
                answer += min(curCount, prevCount);
                prevChar = curChar;
                prevCount = curCount;

                curChar = s[i];
                curCount = 1;
            }
        }
        answer += min(curCount, prevCount);
        return answer;
    }
};