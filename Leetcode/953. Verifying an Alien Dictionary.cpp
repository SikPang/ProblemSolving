class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1) return true;

        unordered_map<char, int> orderMap;

        for (int i=0; i<order.size(); ++i){
            orderMap.insert({order[i], i});
        }

        for (int i=1; i<words.size(); ++i){
            bool isCorrect = false;

            for (int j=0; j<words[i].size() && j<words[i-1].size(); ++j){
                int cur = orderMap[words[i][j]];
                int prev = orderMap[words[i-1][j]];
                if (prev < cur) {
                    isCorrect = true;
                    break;
                }
                if (prev > cur) return false;
            }
            if (!isCorrect && words[i-1].size() > words[i].size()) return false;
        }
        return true;
    }
};