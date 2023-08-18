#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k)
{
    queue<int> que;
    int answer = 1;
    int i = 1;
    int total = 1;
    int temp = 1;

    que.push(menu[order[0]]);
    while (i < order.size())
    {
        if (!que.empty() && que.front() == temp)
        {
            que.pop();
            temp = 0;
        }
        if (total % k == 0)
        {
            que.push(menu[order[i]]);
            ++i;
        }
        if (answer < que.size())
            answer = que.size();
        if (!que.empty())
            ++temp;
        ++total;
    }

    return answer;
}