class Solution {
private:
    void Recur(unordered_map<char, string>& maps, vector<string>& answer, string& digits, string& buffer, int depth){
        if (depth == digits.size()){
            answer.push_back(string(buffer));
            return;
        }

        string curMapped = maps[digits[depth]];
        for (int i=0; i<curMapped.size(); ++i){
            buffer[depth] = curMapped[i];
            Recur(maps, answer, digits, buffer, depth+1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string buffer((int)digits.size(), '0');
        unordered_map<char, string> maps = {
            {'2', "abc"}, {'3', "def"}
            , {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}
            , {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        Recur(maps, answer, digits, buffer, 0);
        return answer;
    }
};