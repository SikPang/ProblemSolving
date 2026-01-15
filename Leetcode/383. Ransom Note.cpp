class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransom;
        
        for (int i=0; i<ransomNote.size(); ++i){
            ransom[ransomNote[i]]++;
        }

        for (int i=0; i<magazine.size(); ++i){
            auto iter = ransom.find(magazine[i]);
            if (iter != ransom.end()){
                iter->second--;
                if (iter->second == 0){
                    ransom.erase(iter);
                }
            }
        }
        return ransom.empty();
    }
};