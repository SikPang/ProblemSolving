class Solution {
private:
    void SplitAndAdd(unordered_map<string, int>& bucket, string& str, char delim){
        vector<string> result;
        stringstream ss(str);
        string token;

        while (ss >> token) {
            ++bucket[token];
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> answer;
        unordered_map<string, int> map;

        SplitAndAdd(map, s1, ' ');
        SplitAndAdd(map, s2, ' ');

        for(auto iter=map.begin(); iter!=map.end(); ++iter){
            if (iter->second == 1) {
                answer.push_back(iter->first);
            }
        }
        return answer;
    }
};