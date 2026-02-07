class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> answer;
        vector<unordered_set<char>> keyboardRows = {
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };

        for (int i=0; i<words.size(); ++i){
            vector<bool> hasWord(3, true);

            for (int j=0; j<words[i].size(); ++j){
                for (int k=0; k<keyboardRows.size(); ++k){
                    if (hasWord[k] == false) continue;
                    char lower = tolower(words[i][j]);
                    if (keyboardRows[k].find(lower) == keyboardRows[k].end()){
                        hasWord[k] = false;
                    }
                }
            }
            if (hasWord[0] || hasWord[1] || hasWord[2]){
                answer.push_back(words[i]);
            }
        }
        return answer;
    }
};