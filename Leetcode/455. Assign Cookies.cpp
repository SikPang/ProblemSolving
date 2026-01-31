class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int answer = 0;
        int sIdx = 0;
        int gIdx = 0;
        while (sIdx < s.size() && gIdx < g.size()){
            if (g[gIdx] <= s[sIdx]){
                ++answer;
                ++gIdx;
                ++sIdx;
            } else{
                ++sIdx;
            }
        }
        return answer;
    }
};