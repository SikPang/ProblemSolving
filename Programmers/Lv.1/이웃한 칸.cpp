#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string& target = board[h][w];
    
    for (int i=0; i<4 ; ++i)
    {
        pair<int, int> next(h+dir[i][0], w+dir[i][1]);

        if (next.first >= 0 && next.first < board.size() 
            && next.second >= 0 && next.second < board[0].size()
           && board[next.first][next.second] == target)
            ++answer;
    }
    return answer;
}
