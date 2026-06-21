class Solution {
private:
    bool TryAdd(array<bool, 11>& buffer, int index){
        if (index < 0 || index > 10) return true;

        bool* target = &buffer[index];
        if (*target == true) return false;
        *target = true;
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); ++i){
            array<bool, 11> buffer = {};
            for (int j=0; j<board[0].size(); ++j){
                if (!TryAdd(buffer, board[i][j] - '0')) return false;
            }
        }

        for (int i=0; i<board.size(); ++i){
            array<bool, 11> buffer = {};
            for (int j=0; j<board[0].size(); ++j){
                if (!TryAdd(buffer, board[j][i] - '0')) return false;
            }
        }

        for (int i=0; i<board.size(); i+=3){
            for (int j=0; j<board[0].size(); j+=3){
                array<bool, 11> buffer = {};
                for (int k=0; k<3; ++k){
                    for (int l=0; l<3; ++l){
                        if (!TryAdd(buffer, board[i+k][j+l] - '0')) return false;
                    }
                }
            }
        }
        return true;
    }
};