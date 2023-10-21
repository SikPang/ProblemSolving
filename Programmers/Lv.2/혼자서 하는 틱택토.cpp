#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<string> board) {
    int oNum = 0;
    int xNum = 0;
    for (int i=0; i<board.size(); ++i)
    {
        for (int j=0; j<board[0].size(); ++j)
        {
            if(board[i][j] == 'O')
                ++oNum;
            else if(board[i][j] == 'X')
                ++xNum;
        }
    }

    string chs = "OX";
    bool win[2] = {false, false};
    for (int k=0; k<2; ++k)
    {
        if ((board[0][0] == chs[k] && board[0][1] == chs[k]  && board[0][2] == chs[k])
        || (board[1][0] == chs[k] && board[1][1] == chs[k]  && board[1][2] == chs[k])
        || (board[2][0] == chs[k] && board[2][1] == chs[k]  && board[2][2] == chs[k])
        || (board[0][0] == chs[k] && board[1][0] == chs[k]  && board[2][0] == chs[k])
        || (board[0][1] == chs[k] && board[1][1] == chs[k]  && board[2][1] == chs[k])
        || (board[0][2] == chs[k] && board[1][2] == chs[k]  && board[2][2] == chs[k])
        || (board[0][0] == chs[k] && board[1][1] == chs[k]  && board[2][2] == chs[k])
        || (board[0][2] == chs[k] && board[1][1] == chs[k]  && board[2][0] == chs[k]))
            win[k] = true;
    }
    if (xNum > oNum
        || abs(xNum - oNum) > 1
        || win[0] == true && win[1] == true
        || win[1] == true && oNum > xNum
        || win[0] == true && oNum == xNum)
        return 0;
    return 1;
}