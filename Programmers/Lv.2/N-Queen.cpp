#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> queen;
int mapSize;
int maxDepth = 0;
int answer = 0;

void NQueen(int depth)
{
    if (depth == mapSize) return;

    for (int i = 0; i < mapSize; ++i)
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
        if (maxDepth < depth)
        {
            maxDepth = depth;
            answer = 1;
        }
        else if (maxDepth == depth)
            ++answer;

		NQueen(depth + 1);

		queen.erase(queen.begin() + queen.size()-1);
    }
}

int solution(int n) 
{
    if(n==2 || n==3) return 0;
    mapSize = n;
    NQueen(0);

    return answer;
}