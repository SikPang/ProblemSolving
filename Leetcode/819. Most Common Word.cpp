class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;

        string buf;
        for (int i=0; i<paragraph.size(); ++i){
            char cur = paragraph[i];

            if (isalpha(cur)){
                cur = tolower(cur);
                buf.push_back(cur);
            } else {
                if (buf.empty()) continue;
                ++map[buf];
                buf.clear();
            }
        }

        if (!buf.empty()){
            ++map[buf];
        }

        pair<string, int> most;
        for (auto iter=map.begin(); iter!=map.end(); ++iter){
            bool isBannedWord = false;
            for (int i=0; i<banned.size(); ++i){
                if (banned[i] == iter->first) {
                    isBannedWord = true;
                    break;
                }
            }
            if (isBannedWord) continue;

            if (iter->second > most.second){
                most = *iter;
            }
        }
        return most.first;
    }
};