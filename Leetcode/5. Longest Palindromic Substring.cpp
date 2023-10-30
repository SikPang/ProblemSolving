class Solution {
private:
    bool isPalindrom(string& s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        string answer = s.substr(0,1);

        for (int start=0; start<s.length(); ++start)
        {
            for (int end=start; end<s.length(); ++end)
            {
                if (answer.length() < end - start + 1 && isPalindrom(s, start, end))
                    answer = s.substr(start, end-start+1);
            }
        }
        return answer;
    }
};