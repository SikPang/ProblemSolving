class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans{1, 0};

        for (int i=0; i<s.size(); ++i){
            int needed = widths[s[i] - 'a'];

            if (ans[1] + needed > 100){
                ++ans[0];
                ans[1] = needed;
            } else {
                ans[1] += needed;
            }
        }
        return ans;
    }
};