class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;

        for (int i=0; i<haystack.size() - needle.size() + 1; ++i){
            int startIdx = i;
            bool isCorrect = true;

            for (int j=0; j<needle.size() && startIdx<haystack.size(); ++j, ++startIdx){
                if (haystack[startIdx] != needle[j]) {
                    isCorrect = false;
                    break;
                }
            }

            if (isCorrect) return i;
        }
        return -1;
    }
};