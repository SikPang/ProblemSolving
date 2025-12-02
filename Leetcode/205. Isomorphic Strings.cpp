class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap;
        unordered_set<char> dupChecker;

        string target = string(t);
        for (int i=0; i<s.size(); ++i){
            unordered_map<char, char>::iterator iter = charMap.find(s[i]);
            if (iter == charMap.end()){
                if (dupChecker.find(t[i]) != dupChecker.end()) return false;
                charMap.insert(make_pair(s[i], t[i]));
                dupChecker.insert(t[i]);
                s[i] = t[i];
            } else{
                s[i] = iter->second;
            }
        }

        return s == target;
    }
};