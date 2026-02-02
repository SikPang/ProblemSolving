class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i=1; i<=s.size()/2; ++i){
            if (s.size() % i != 0) continue;

            string target = "";
            bool isRepeated = true;
            for (int j=0; j<s.size()-i+1; j+=i){
                string substr = "";
                for (int k=0; k<i; ++k){
                    substr += s[j+k];
                }

                if (target == ""){
                    target = substr;
                } else {
                    if (target != substr){
                        isRepeated = false;
                        break;
                    }
                }
            }
            if (isRepeated) return true;
        }
        return false;
    }
};