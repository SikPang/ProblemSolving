class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parentheses;

        for (int i=0; i<s.size(); ++i){
            if (s[i] == '(') {
                parentheses.push(i);
            } else {
                if (parentheses.size() > 0 && s[parentheses.top()] == '(') {
                    parentheses.pop();
                } else {
                    parentheses.push(i);
                }
            }
        }
        
        int maxLen = parentheses.size() == 0 ? s.size() : 0;
        int right = s.size() - 1;

        while (parentheses.size() > 0){
            int idx = parentheses.top();
            parentheses.pop();
            maxLen = max(maxLen, right - idx);
            right = idx - 1;
        }
        maxLen = max(maxLen, right + 1);
        return maxLen;
    }
};