class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;
        for (int i=0; i<s.size(); ++i){
            counter[s[i]]++;
        }

        int countOfTwo = 0;
        bool hasSolo = false;
        for (auto iter=counter.begin(); iter!=counter.end(); ++iter){
            countOfTwo += iter->second / 2;
            if (iter->second % 2 == 1){
                hasSolo = true;
            }
        }
        return countOfTwo * 2 + (hasSolo ? 1 : 0);
    }
};