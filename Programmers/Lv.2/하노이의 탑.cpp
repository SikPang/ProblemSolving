#include <string>
#include <vector>
using namespace std;

vector<vector<int>> answer;

void HanoiTower(int depth, int start, int dest, int other, int max) {
    if (depth == max) return;

    HanoiTower(depth + 1, start, other, dest, max);

    vector<int> inner = { start, dest };
    answer.push_back(inner);

    HanoiTower(depth + 1, other, dest, start, max);
}

vector<vector<int>> solution(int n) {
    HanoiTower(0, 1, 3, 2, n);

    return answer;
}