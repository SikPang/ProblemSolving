#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> queen;
int maxDepth;
int answer = 0;

void NQueen(int depth)
{
    if (depth == maxDepth)
    {
        ++answer;
        return;
    }

    for (int i = 0; i < maxDepth; ++i)
    {
        if (depth != 0)
        {
            bool isBreaked = false;
            for (int j = 0; j < queen.size(); ++j)
            {
                if (queen[j].second == i
                    || queen[j].first + queen[j].second == depth + i
                    || queen[j].first - queen[j].second == depth - i)
                {
                    isBreaked = true;
                    break;
                }
            }
            if (isBreaked) continue;
        }
        queen.push_back({ depth, i });

        NQueen(depth + 1);

        queen.erase(queen.begin() + queen.size() - 1);
    }
}

int solution(int n)
{
    maxDepth = n;
    NQueen(0);

    return answer;
}