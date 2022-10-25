#include <vector>

using namespace std;

vector<int> num;
int answer = 0;
int sum = 0;

void dfs(int depth, int index)
{
    if (depth == 3)
    {
        if (sum == 0)
            ++answer;
        return;
    }

    for (int i = index; i < num.size(); ++i)
    {
        sum += num[i];

        dfs(depth + 1, i + 1);
        
        sum -= num[i];
    }
}

int solution(vector<int> number) 
{
    num = number;

    dfs(0, 0);

    return answer;
}