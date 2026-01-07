class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternMap;
        unordered_set<string> sSet;
        string word = "";
        int patternIdx = 0;

        for (int i=0; i<s.size(); ++i){
            if (s[i] == ' '){
                if (pattern.size() <= patternIdx) return false;

                char curPattern = pattern[patternIdx];
                if (patternMap.find(curPattern) == patternMap.end()){
                    if (sSet.find(word) != sSet.end()) return false;
                    patternMap.insert(make_pair(curPattern, word));
                    sSet.insert(word);
                } else if (patternMap[curPattern] != word) {
                    return false;
                }
                ++patternIdx;
                word = "";
            } else {
                word.push_back(s[i]);
            }
        }

        if (word != ""){
            char curPattern = pattern[patternIdx];
            if (patternMap.find(curPattern) == patternMap.end()){
                if (sSet.find(word) != sSet.end()) return false;
            } else if (patternMap[curPattern] != word) {
                return false;
            }
            ++patternIdx;
        }
        return pattern.size() == patternIdx;
    }
};