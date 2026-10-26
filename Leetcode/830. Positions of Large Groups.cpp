class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> answer;

        int startIdx = 0;
        char ch = s[0];
        for(int i=1; i<s.size(); ++i){
            if (s[i] == ch) continue;

            if (i - startIdx >= 3){
                answer.push_back({startIdx, i-1});
            }
            startIdx = i;
            ch = s[i];
        }

        if (s[s.size()-1] == ch && s.size() - startIdx >= 3){
            answer.push_back({startIdx, (int)s.size()-1});
        }
        return answer;
    }
};