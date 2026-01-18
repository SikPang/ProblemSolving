class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> checker;

        for (int i=0; i<s.size(); ++i){
            checker[s[i]]++;
        }

        for (int i=0; i<s.size(); ++i){
            if (checker[s[i]] == 1) return i;
        }
        return -1;
    }
};