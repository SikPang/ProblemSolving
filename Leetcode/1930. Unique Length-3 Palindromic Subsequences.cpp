class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> uniqueAlpha;
        int answer = 0;

        for (int i=0; i<s.length(); ++i)
            uniqueAlpha.insert(s[i]);

        for (auto iter=uniqueAlpha.begin(); iter!=uniqueAlpha.end(); ++iter)
        {
            unordered_set<char> uniqueCenter;
            int left = s.find(*iter);
            int right = s.rfind(*iter);

            for (int i=left+1; i<right; ++i)
                uniqueCenter.insert(s[i]);
            answer += uniqueCenter.size();
        }
        return answer;
    }
};