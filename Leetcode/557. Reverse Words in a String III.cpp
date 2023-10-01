class Solution {
public:
    string reverseWords(string s) {
        stack<char> stack;
        string answer = "";
        answer.reserve(s.length());

        for (int i=0; i<=s.length(); ++i)
        {
            if (i == s.length() || s[i] == ' ')
            {
                while (!stack.empty())
                {
                    answer += stack.top();
                    stack.pop();
                }
                if (i < s.length())
                    answer += ' ';
            }
            else
                stack.push(s[i]);
        }
        return answer;
    }
};