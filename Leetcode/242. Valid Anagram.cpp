class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;

        for (int i=0; i<s.size(); ++i){
            myMap[s[i]]++;
        }

        for (int i=0; i<t.size(); ++i){
            auto iter = myMap.find(t[i]);

            if (iter == myMap.end()) return false;

            if (iter->second == 1){
                myMap.erase(t[i]);
            } else{
                iter->second--;
            }
        }

        return myMap.empty();
    }
};