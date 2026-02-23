class Solution {
public:
    bool detectCapitalUse(string word) {
        bool needToCheckUpperCase = isupper(word[0]);
        bool needToCheckLowerCase = islower(word[0]) || (needToCheckUpperCase && word.size() > 1 && islower(word[1]));
        if (needToCheckLowerCase){
            needToCheckUpperCase = false;
        }

        for (int i=1; i<word.size(); ++i){
            if (needToCheckUpperCase){
                if (!isupper(word[i])) return false;
            } else if (needToCheckLowerCase){
                if (!islower(word[i])) return false;
            }
        }
        return true;
    }
};