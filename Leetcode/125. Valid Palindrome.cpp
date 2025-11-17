class Solution {
public:
    bool isPalindrome(string s) {
        string newA = "";

        for (int i=0; i<s.size(); ++i){
            s[i] = tolower(s[i]);
            if (isalnum(s[i])){
                newA.push_back(s[i]);
            }
        }

        if (newA.size() == 0) return true;
        
        for (int i=0; i<newA.size()/2.0f; ++i){
            if (newA[i] != newA[newA.size()-i-1]) return false;
        }
        return true;
    }
};