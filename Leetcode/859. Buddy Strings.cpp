class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        vector<int> sAlphabets(26);
        vector<int> gAlphabets(26);
        vector<char> sVec;
        vector<char> gVec;

        for (int i=0; i<s.size(); ++i){
            ++sAlphabets[s[i]-'a'];
            ++gAlphabets[goal[i]-'a'];

            if (s[i] != goal[i]){
                sVec.push_back(s[i]);
                gVec.push_back(goal[i]);
            }
        }

        if (sVec.empty()) {
            for (int i=0; i<sAlphabets.size(); ++i){
                if (sAlphabets[i] >= 2) return true;
            }
            return false;
        }
        if (sVec.size() != 2) return false;
        return gVec[1] == sVec[0] && sVec[1] == gVec[0];
    }
};