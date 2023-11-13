class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> idx;

        vowels.reserve(s.length());
        idx.reserve(s.length());
        for (int i=0; i<s.length(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
                || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vowels.push_back(s[i]);
                idx.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());

        for (int i=0; i<idx.size(); ++i)
            s[idx[i]] = vowels[i];
        return s;
    }
};