class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<vector<int>, vector<string>> map;

        for (int i=0; i<strs.size(); ++i){
            vector<int> counter(26);
            for (int j=0; j<strs[i].size(); ++j){
                ++counter[strs[i][j] - 'a'];
            }
            map[counter].push_back(strs[i]);
        }

        for (auto iter=map.begin(); iter!=map.end(); ++iter){
            ret.push_back(iter->second);
        }
        return ret;
    }
};