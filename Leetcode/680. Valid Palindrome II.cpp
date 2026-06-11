class Solution {
private:
    bool validPalindromeInception(string& s, int i, int back, bool hasChance){
        for (int half = s.size()/2; i<half; ++i, --back){
            if (s[i] == s[back]) continue;

            if (!hasChance) return false;

            if (i + 1 == back) {
                return true;
            } else if (s[i] == s[back - 1] || s[i+1] == s[back]) {
                return validPalindromeInception(s, i+1, back, false) 
                    || validPalindromeInception(s, i, back-1, false);
            } else {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        return validPalindromeInception(s, 0, s.size()-1, true);
    }
};