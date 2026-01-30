class Solution {
public:
    int countSegments(string s) {
        int wordCount = 0;
        char beforeWord = ' ';

        for (int i=0; i<s.size(); ++i){
            if (s[i] != ' ' && beforeWord == ' ') {
                ++wordCount;
            }
            beforeWord = s[i];
        }
        return wordCount;
    }
};