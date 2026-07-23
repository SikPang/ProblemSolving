class Solution {
private:
    bool canPlace(vector<string>& board, int y, int x){
        for (int i=0; i<board.size(); ++i){
            if (i != y && board[i][x] == 'Q') return false;
        }

        // 우 대각선 상
        for (int i=1; i<board.size(); ++i){
            if (y-i < 0 || x+i >= board.size()) break;
            if (board[y-i][x+i] == 'Q') return false;
        }

        // 우 대각선 하
        for (int i=1; i<board.size(); ++i){
             if (y+i >= board.size() || x-i < 0) break;
            if (board[y+i][x-i] == 'Q') return false;
        }

        // 좌 대각선 상
        for (int i=1; i<board.size(); ++i){
            if (y-i < 0 || x-i < 0) break;
            if (board[y-i][x-i] == 'Q') return false;
        }

        // 좌 대각선 하
        for (int i=1; i<board.size(); ++i){
             if (y+i >= board.size() || x+i >= board.size()) break;
            if (board[y+i][x+i] == 'Q') return false;
        }
        return true;
    }

    void nQueenRecur(vector<vector<string>>& answer, vector<string>& board, int depth) {
        if (depth == board.size()) {
            answer.push_back(board);
            return;
        }

        for (int i=0; i<board.size(); ++i){
            if (!canPlace(board, depth, i)) continue;

            board[depth].assign(board.size(), '.');
            board[depth][i] = 'Q';
            nQueenRecur(answer, board, depth+1);
            board[depth].assign(board.size(), '.');
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board(n, string(n, ' '));
        nQueenRecur(answer, board, 0);
        return answer;
    }
};