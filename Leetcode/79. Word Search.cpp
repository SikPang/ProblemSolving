class Solution {
private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void existRecur(vector<vector<char>>& board, vector<vector<bool>>& isVisited, string& word, int y, int x, int depth){
        if (depth == word.size()) throw true;

        for (int i=0; i<dir.size(); ++i){
            int nextY = dir[i].first + y;
            int nextX = dir[i].second + x;

            if (nextY < 0 || nextY >= board.size() || nextX < 0 || nextX >= board[0].size()) continue;
            if (board[nextY][nextX] != word[depth] || isVisited[nextY][nextX]) continue;

            isVisited[nextY][nextX] = true;
            existRecur(board, isVisited, word, nextY, nextX, depth+1);
            isVisited[nextY][nextX] = false;
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size()));

        for (int i=0; i<board.size(); ++i){
            for (int j=0; j<board[0].size(); ++j){
                if (board[i][j] != word[0]) continue;

                isVisited[i][j] = true;
                try{
                    existRecur(board, isVisited, word, i, j, 1);
                } catch(bool a){
                    return true;
                }
                isVisited[i][j] = false;
            }
        }
        return false;
    }
};