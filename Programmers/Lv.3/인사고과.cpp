#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

struct Score{
    int idx;
    int score1;
    int score2;
    Score(int idx, int score1, int score2) 
        : idx(idx), score1(score1), score2(score2) {}
};

int solution(vector<vector<int>> scores) {
    vector<Score> board;

    board.reserve(scores.size());

    for (int i = 0; i < scores.size(); ++i) {
        board.push_back(Score(i, scores[i][0], scores[i][1]));
    }

    sort(board.begin(), board.end(), [](const Score& a, const Score& b) {
        if (a.score1 == b.score1) {
            return a.score2 < b.score2;
        }

        return a.score1 > b.score1;
    });

    int maxScore2 = 0;
    int wanhoScore = scores[0][0] + scores[0][1];
    int rank = 1;

    for (int i = 0; i < board.size(); ++i) {
        Score& cur = board[i];

        if (cur.score2 < maxScore2) {
            if (cur.idx == 0) {
                return -1;
            }

            continue;
        }

        maxScore2 = max(maxScore2, cur.score2);

        if (cur.score1 + cur.score2 > wanhoScore) {
            ++rank;
        }
    }

    return rank;
}