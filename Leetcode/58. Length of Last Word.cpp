class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastStartIdx = 0;
        for (int i = s.size()-1; i >= 0; --i){
            if (s[i] != ' '){
                lastStartIdx = i;
                break;
            }
        }

        int length = 0;
        for (int i = lastStartIdx; i >= 0; --i){
            if (s[i] == ' ') break;
            ++length;
        }
        return length;
    }
};