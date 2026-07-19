class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastAppearIdx(26);
        vector<bool> used(26);
        string answer;

        for (int i=0; i<s.size(); ++i){
            lastAppearIdx[s[i] - 'a'] = i;
        }

        for (int i=0; i<s.size(); ++i){
            if (used[s[i]-'a']) continue;

            if (answer.empty() 
                || answer.back() < s[i] 
                || lastAppearIdx[answer.back() - 'a'] <= i){
                answer.push_back(s[i]);
                used[s[i]-'a'] = true;
                continue;
            }

            while (!answer.empty() 
                && answer.back() > s[i] 
                && lastAppearIdx[answer.back() - 'a'] > i) {
                used[answer.back()-'a'] = false;
                answer.pop_back();
            }
            used[s[i]-'a'] = true;
            answer.push_back(s[i]);
        }
        return answer;
    }
};