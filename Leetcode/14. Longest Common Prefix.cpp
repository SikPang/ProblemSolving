class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b) { return a.size() < b.size(); });
        string answer(strs[0]);

        for (int i=1; i<strs.size(); ++i){
            for (int j=0; j<strs[i].size() && answer.size(); ++j){
                if (strs[i][j] != answer[j]){
                    answer = answer.substr(0, j);
                    break;
                }
            }
        }
        return answer;
    }
};