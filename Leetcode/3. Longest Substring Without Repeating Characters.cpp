class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        unordered_set<char> subStr;
        int maxLength = 0;
        int left = 0;

        for (int right=0; right<s.size(); ++right){
            char cur = s[right];
            if (subStr.find(cur) == subStr.end()){
                subStr.insert(cur);
                maxLength = max((int)subStr.size(), maxLength);
            } else {
                while (subStr.find(cur) != subStr.end()){
                    subStr.erase(s[left]);
                    ++left;
                }
                subStr.insert(cur);
            }
        }
        return maxLength;
    }
};