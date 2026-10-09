class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> alphabets(26);
        string answer;

        for (int i=0; i<licensePlate.size(); ++i){
            if (!isalpha(licensePlate[i])) continue;
            alphabets[tolower(licensePlate[i])-'a']++;
        }

        for (int i=0; i<words.size(); ++i){
            if (!answer.empty() && words[i].size() >= answer.size()) continue;

            vector<int> copy(alphabets);
            for (int j=0; j<words[i].size(); ++j){
                --copy[words[i][j]-'a'];
            }

            bool isCompletingWord = true;
            for (int j=0; j<copy.size(); ++j){
                if (copy[j] > 0) {
                    isCompletingWord = false;
                    break;
                }
            }
            if (isCompletingWord){
                answer = words[i];
            }
        }
        return answer;
    }
};