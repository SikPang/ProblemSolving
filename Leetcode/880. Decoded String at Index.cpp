class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        
        for (int i=0; i<s.length(); ++i)
        {
            if (isdigit(s[i]))
                len *= s[i] - '0';
            else
                ++len;
        }

        for (int i=s.length()-1; i>=0; --i)
        {
            if (isdigit(s[i]))
            {
                len /= s[i] - '0';
                k %= len;
            }
            else
            {
                if (k == 0 || k == len)
                    return string(1, s[i]);
                --len;
            }
        }
        return "NONE";
    }
};