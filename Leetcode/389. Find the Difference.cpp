class Solution {
public:
    char findTheDifference(string s, string t) {
        int charSet['z' + 1] = {};

        for (int i=0; i<s.length(); ++i)
            ++charSet[s[i]];

        for (int i=0; i<t.length(); ++i)
        {
            if (charSet[t[i]] == 0)
                return t[i];
            --charSet[t[i]];
        }
        return NULL;
    }
};