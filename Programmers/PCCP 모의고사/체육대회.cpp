#include <string>
#include <vector>

using namespace std;

bool isVisited[10] = {};
int answer = 0;
int sum = 0;

void recursion(int depth, vector<vector<int>>* ability)
{
    if (depth == (*ability)[0].size())
    {
        if (sum > answer)
            answer = sum;
        return;
    }
    for (int i = 0; i < (*ability).size(); ++i)
    {
        if (isVisited[i]) continue;

        isVisited[i] = true;
        sum += (*ability)[i][depth];
        recursion(depth + 1, ability);
        sum -= (*ability)[i][depth];
        isVisited[i] = false;
    }
}

int solution(vector<vector<int>> ability)
{
    recursion(0, &ability);

    return answer;
}