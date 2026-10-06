class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char firstChar = letters[0];
        sort(letters.begin(), letters.end());

        for (int i=0; i<letters.size(); ++i){
            if (target < letters[i]) return letters[i];
        }
        return firstChar;
    }
};