class Solution {
public:
    string convert(string s, int numRows) {
        auto board = vector<string>(numRows);
        
        for (int i=0; i<s.size(); ){
            for (int j=0; j<numRows && i<s.size(); ++j, ++i){
                board[j].push_back(s[i]);
            }
            for (int j=numRows-2; j>=1 && i<s.size(); --j, ++i){
                board[j].push_back(s[i]);
            }
        }

        string answer;
        answer.reserve(s.size());
        for (int i=0; i<board.size(); ++i){
            answer += board[i];
        }
        return answer;
    }
};